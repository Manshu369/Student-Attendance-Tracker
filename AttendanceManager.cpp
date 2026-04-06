#include "AttendanceManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <sys/stat.h>

AttendanceManager::AttendanceManager(const std::string& dataFile, const std::string& reportFile)
    : dataFile(dataFile), reportFile(reportFile) {
    ensureDirectories();
    loadFromFile();
}

void AttendanceManager::ensureDirectories() {
    mkdir("data", 0777);
    mkdir("reports", 0777);
}

void AttendanceManager::addStudent(const std::string& name) {
    if (findStudent(name)) {
        std::cout << "Student already exists.\n";
        return;
    }
    students.emplace_back(name);
    std::cout << "Student \"" << name << "\" added.\n";
}

Student* AttendanceManager::findStudent(const std::string& name) {
    for (auto& s : students) {
        if (s.getName() == name) return &s;
    }
    return nullptr;
}

void AttendanceManager::addSubjectToStudent(const std::string& studentName, const std::string& subject) {
    Student* s = findStudent(studentName);
    if (!s) { std::cout << "Student not found.\n"; return; }
    s->addSubject(subject);
    std::cout << "Subject \"" << subject << "\" added to " << studentName << ".\n";
}

void AttendanceManager::markAttendance(const std::string& studentName, const std::string& subject, bool present) {
    Student* s = findStudent(studentName);
    if (!s) { std::cout << "Student not found.\n"; return; }
    try {
        s->markAttendance(subject, present);
        std::cout << "Marked " << (present ? "Present" : "Absent") << " for " << studentName << " in " << subject << ".\n";
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

void AttendanceManager::displayAttendance(const std::string& studentName) const {
    for (const auto& s : students) {
        if (s.getName() == studentName) {
            std::cout << "\n--- Attendance for " << studentName << " ---\n";
            std::cout << std::left << std::setw(20) << "Subject"
                      << std::setw(10) << "Present"
                      << std::setw(10) << "Total"
                      << std::setw(12) << "Percentage"
                      << "Status\n";
            std::cout << std::string(60, '-') << "\n";

            for (const auto& subject : s.getSubjects()) {
                auto att = s.getAllAttendance().at(subject);
                double pct = s.getPercentage(subject);
                std::string status = s.isBelowThreshold(subject) ? "⚠ LOW" : "OK";

                std::cout << std::left << std::setw(20) << subject
                          << std::setw(10) << att.first
                          << std::setw(10) << att.second
                          << std::setw(12) << std::fixed << std::setprecision(1) << pct
                          << status << "\n";
            }
            return;
        }
    }
    std::cout << "Student not found.\n";
}

void AttendanceManager::displayAllStudents() const {
    if (students.empty()) { std::cout << "No students added yet.\n"; return; }
    std::cout << "\n--- All Students ---\n";
    for (const auto& s : students) {
        std::cout << "  - " << s.getName() << "\n";
    }
}

void AttendanceManager::showWarnings() const {
    std::cout << "\n⚠ Attendance Warnings (below 75%) ⚠\n";
    bool anyWarning = false;
    for (const auto& s : students) {
        for (const auto& subject : s.getSubjects()) {
            if (s.isBelowThreshold(subject)) {
                anyWarning = true;
                std::cout << "  " << s.getName() << " | " << subject
                          << " | " << std::fixed << std::setprecision(1)
                          << s.getPercentage(subject) << "%\n";
            }
        }
    }
    if (!anyWarning) std::cout << "  All students are above 75%. \n";
}

void AttendanceManager::exportReport() const {
    std::ofstream file(reportFile);
    if (!file) { std::cout << "Failed to create report.\n"; return; }

    file << "========================================\n";
    file << "       STUDENT ATTENDANCE REPORT\n";
    file << "========================================\n\n";

    for (const auto& s : students) {
        file << "Student: " << s.getName() << "\n";
        file << std::left << std::setw(20) << "Subject"
             << std::setw(10) << "Present"
             << std::setw(10) << "Total"
             << "Percentage\n";
        file << std::string(50, '-') << "\n";

        for (const auto& subject : s.getSubjects()) {
            auto att = s.getAllAttendance().at(subject);
            file << std::left << std::setw(20) << subject
                 << std::setw(10) << att.first
                 << std::setw(10) << att.second
                 << std::fixed << std::setprecision(1)
                 << s.getPercentage(subject) << "%"
                 << (s.isBelowThreshold(subject) ? "  [WARNING]" : "") << "\n";
        }
        file << "\n";
    }

    std::cout << "Report exported to " << reportFile << "\n";
}

void AttendanceManager::saveToFile() const {
    std::ofstream file(dataFile);
    if (!file) { std::cout << "Failed to save data.\n"; return; }

    for (const auto& s : students) {
        file << "STUDENT:" << s.getName() << "\n";
        for (const auto& subject : s.getSubjects()) {
            auto att = s.getAllAttendance().at(subject);
            file << "SUBJECT:" << subject << ":" << att.first << ":" << att.second << "\n";
        }
    }
}

void AttendanceManager::loadFromFile() {
    std::ifstream file(dataFile);
    if (!file) return;

    std::string line;
    Student* current = nullptr;

    while (std::getline(file, line)) {
        if (line.substr(0, 8) == "STUDENT:") {
            std::string name = line.substr(8);
            students.emplace_back(name);
            current = &students.back();
        } else if (line.substr(0, 8) == "SUBJECT:" && current) {
            std::stringstream ss(line.substr(8));
            std::string subject, presentStr, totalStr;
            std::getline(ss, subject, ':');
            std::getline(ss, presentStr, ':');
            std::getline(ss, totalStr, ':');
            current->addSubject(subject);
            int present = std::stoi(presentStr);
            int total = std::stoi(totalStr);
            for (int i = 0; i < total; i++) {
                current->markAttendance(subject, i < present);
            }
        }
    }
}
