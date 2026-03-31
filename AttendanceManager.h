#pragma once
#include "Student.h"
#include <vector>
#include <string>

class AttendanceManager {
private:
    std::vector<Student> students;
    std::string dataFile;
    std::string reportFile;

    void ensureDirectories();

public:
    AttendanceManager(const std::string& dataFile = "data/attendance.txt",
                      const std::string& reportFile = "reports/report.txt");

    void addStudent(const std::string& name);
    Student* findStudent(const std::string& name);
    void addSubjectToStudent(const std::string& studentName, const std::string& subject);
    void markAttendance(const std::string& studentName, const std::string& subject, bool present);
    void displayAttendance(const std::string& studentName) const;
    void displayAllStudents() const;
    void exportReport() const;
    void saveToFile() const;
    void loadFromFile();
    void showWarnings() const;
};
