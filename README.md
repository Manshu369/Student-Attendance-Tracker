# 📋 Student Attendance Tracker

A command-line application built in **C++** that helps track student attendance across multiple subjects, auto-calculates attendance percentage, warns when below 75%, and exports reports to a text file.

---

## 🎯 Features

- ✅ Add multiple students
- ✅ Add multiple subjects per student
- ✅ Mark attendance as Present / Absent per subject
- ✅ Auto-calculate attendance percentage
- ✅ Warn when attendance drops below 75%
- ✅ Export full attendance report to a `.txt` file
- ✅ Persistent data — saves and loads from file automatically

---

## 🛠️ Tech Stack

| Tech | Usage |
|------|-------|
| C++ | Core language |
| OOP (Classes & Objects) | Student and Manager structure |
| File I/O | Save/load data, export reports |
| STL (map, vector) | Data storage |

---

## 📁 Project Structure
```
StudentAttendanceTracker/
├── main.cpp                  # Entry point, CLI menu
├── Student.h                 # Student class declaration
├── Student.cpp               # Student class implementation
├── AttendanceManager.h       # Manager class declaration
├── AttendanceManager.cpp     # Manager class implementation
├── data/
│   └── attendance.txt        # Auto-generated persistent storage
├── reports/
│   └── report.txt            # Auto-generated exported report
└── README.md
```

---

## 🚀 How to Run

### Prerequisites
- A C++ compiler — `g++` (comes with GCC)
- Works on **Windows**, **macOS**, and **Linux**

### Step 1 — Clone the repository
```bash
git clone https://github.com/YOUR_USERNAME/StudentAttendanceTracker.git
cd StudentAttendanceTracker
```

### Step 2 — Compile
```bash
g++ -o attendance main.cpp Student.cpp AttendanceManager.cpp
```

### Step 3 — Run
```bash
# On Linux / macOS
./attendance

# On Windows
attendance.exe
```

---

## 🖥️ Menu Options
```
================================
  Student Attendance Tracker
================================

--- MENU ---
1. Add Student
2. Add Subject to Student
3. Mark Attendance
4. View Student Attendance
5. View All Students
6. Show Warnings (below 75%)
7. Export Report
8. Save & Exit
```

---

## 📊 Sample Output
```
--- Attendance for Mansh ---
Subject              Present   Total     Percentage  Status
------------------------------------------------------------
Mathematics          8         10        80.0        OK
Physics              5         9         55.6        ⚠ LOW
Chemistry            9         10        90.0        OK

⚠ Attendance Warnings (below 75%) ⚠
  Mansh | Physics | 55.6%
```

---

## 📄 Exported Report
```
========================================
       STUDENT ATTENDANCE REPORT
========================================

Student: Mansh
Subject              Present   Total     Percentage
--------------------------------------------------
Mathematics          8         10        80.0%
Physics              5         9         55.6%  [WARNING]
Chemistry            9         10        90.0%
```

---

## 💡 Skills Demonstrated

- Object-Oriented Programming (Classes, Encapsulation)
- File I/O (reading and writing persistent data)
- STL containers (`std::map`, `std::vector`, `std::pair`)
- Exception handling
- Clean CLI interface design

---

## 👨‍💻 Author

**Mansh**
B.Tech Student
[GitHub](https://github.com/Manshu369)
