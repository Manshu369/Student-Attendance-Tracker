#include <iostream>
#include <string>
#include <limits>
#include "AttendanceManager.h"

void clearInput() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    AttendanceManager manager;
    int choice;

    std::cout << "================================\n";
    std::cout << "  Student Attendance Tracker\n";
    std::cout << "================================\n";

    while (true) {
        std::cout << "\n--- MENU ---\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Add Subject to Student\n";
        std::cout << "3. Mark Attendance\n";
        std::cout << "4. View Student Attendance\n";
        std::cout << "5. View All Students\n";
        std::cout << "6. Show Warnings (below 75%)\n";
        std::cout << "7. Export Report\n";
        std::cout << "8. Save & Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        clearInput();

        if (choice == 1) {
            std::string name;
            std::cout << "Enter student name: ";
            std::getline(std::cin, name);
            manager.addStudent(name);

        } else if (choice == 2) {
            std::string name, subject;
            std::cout << "Enter student name: ";
            std::getline(std::cin, name);
            std::cout << "Enter subject name: ";
            std::getline(std::cin, subject);
            manager.addSubjectToStudent(name, subject);

        } else if (choice == 3) {
            std::string name, subject;
            char status;
            std::cout << "Enter student name: ";
            std::getline(std::cin, name);
            std::cout << "Enter subject name: ";
            std::getline(std::cin, subject);
            std::cout << "Present? (y/n): ";
            std::cin >> status;
            clearInput();
            manager.markAttendance(name, subject, status == 'y' || status == 'Y');

        } else if (choice == 4) {
            std::string name;
            std::cout << "Enter student name: ";
            std::getline(std::cin, name);
            manager.displayAttendance(name);

        } else if (choice == 5) {
            manager.displayAllStudents();

        } else if (choice == 6) {
            manager.showWarnings();

        } else if (choice == 7) {
            manager.exportReport();

        } else if (choice == 8) {
            manager.saveToFile();
            std::cout << "Data saved. Goodbye!\n";
            break;

        } else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
