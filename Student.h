#pragma once
#include <string>
#include <map>
#include <vector>

struct Attendance {
    int present = 0;
    int total = 0;
};

class Student {
private:
    std::string name;
    std::map<std::string, Attendance> attendance;

public:
    Student();
    Student(const std::string& name);

    std::string getName() const;
    void addSubject(const std::string& subject);
    void markAttendance(const std::string& subject, bool present);
    double getPercentage(const std::string& subject) const;
    bool isBelowThreshold(const std::string& subject, double threshold = 75.0) const;
    std::map<std::string, Attendance> getAllAttendance() const;
    std::vector<std::string> getSubjects() const;
};
