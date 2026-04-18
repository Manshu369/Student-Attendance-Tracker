#pragma once
#include <string>
#include <map>
#include <vector>  

class Student {
private:
    std::string name;
    std::map<std::string, std::pair<int, int>> attendance; // subject -> {present, total}

public:
    Student();
    Student(const std::string& name);

    std::string getName() const;
    void addSubject(const std::string& subject);
    void markAttendance(const std::string& subject, bool present);
    double getPercentage(const std::string& subject) const;
    bool isBelowThreshold(const std::string& subject, double threshold = 75.0) const;
    std::map<std::string, std::pair<int, int>> getAllAttendance() const;
    std::vector<std::string> getSubjects() const;
};
