#include "Student.h"
#include <stdexcept>
#include <vector>

Student::Student() : name("Unknown") {}

Student::Student(const std::string& name) : name(name) {}

std::string Student::getName() const {
    return name;
}

void Student::addSubject(const std::string& subject) {
    if (attendance.find(subject) == attendance.end()) {
        attendance[subject] = {0, 0};
    }
}

void Student::markAttendance(const std::string& subject, bool present) {
    if (attendance.find(subject) == attendance.end()) {
        throw std::invalid_argument("Subject not found: " + subject);
    }
attendance[subject].total++;
if (present) attendance[subject].present++;
}

double Student::getPercentage(const std::string& subject) const {
    auto it = attendance.find(subject);
    if (it == attendance.end() || it->second.second == 0) return 0.0;
  return (100.0 * it->second.present) / it->second.total;
}

bool Student::isBelowThreshold(const std::string& subject, double threshold) const {
    return getPercentage(subject) < threshold;
}

std::map<std::string, Attendance> Student::getAllAttendance() const {
    return attendance;
}

std::vector<std::string> Student::getSubjects() const {
    std::vector<std::string> subjects;
    for (const auto& pair : attendance) {
        subjects.push_back(pair.first);
    }
    return subjects;
}
