/**
 * @file main.cpp
 * @brief Smart Campus Management System - Main Entry Point
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * This file wires together all 6 modules and provides a console-driven
 * demo that exercises every OOP concept in the checklist.
 */

#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Module 1 – Person Hierarchy
#include "person/Person.h"
#include "person/Student.h"
#include "person/GradStudent.h"
#include "person/Faculty.h"
#include "person/Staff.h"

// Module 2 – Course & Enrollment
#include "course/Course.h"
#include "course/Enrollment.h"

// Module 3 – Library
#include "library/Library.h"
#include "library/Book.h"
#include "library/Journal.h"

// Module 4 – Finance
#include "finance/FeeRecord.h"
#include "finance/Invoice.h"

// Module 5 – Hostel
#include "hostel/Room.h"
#include "hostel/HostelBlock.h"
#include "hostel/HostelManager.h"

// Module 6 – Reports & Utilities
#include "utils/Reports.h"
#include "utils/Exceptions.h"

// ─── Global data arrays (simple, no STL containers) ───────────────────────
const int MAX_STUDENTS = 20;
const int MAX_FACULTY  = 10;
const int MAX_COURSES  = 10;

Student* students[MAX_STUDENTS];
Faculty* faculty[MAX_FACULTY];
Course*  courses[MAX_COURSES];
int      studentCount = 0;
int      facultyCount = 0;
int      courseCount  = 0;

// ─── Forward declarations for menu sections ───────────────────────────────
void demoModule1();
void demoModule2();
void demoModule3(Library& lib);
void demoModule4();
void demoModule5();
void demoModule6(Library& lib, HostelManager& hostelMgr);
void showMainMenu();
void cleanupGlobals();

// ─── Seed data helpers ────────────────────────────────────────────────────
void seedData() {
    // Students
    students[studentCount++] = new Student("Ahmed Ali",     "35202-1234567-1", 20, "0300-1111111", "21-CS-001", 3, 3.8);
    students[studentCount++] = new Student("Sara Khan",     "35202-2345678-2", 21, "0300-2222222", "21-CS-002", 3, 3.2);
    students[studentCount++] = new Student("Usman Malik",   "35202-3456789-3", 22, "0300-3333333", "20-CS-010", 5, 2.9);
    students[studentCount++] = new GradStudent("Fatima Naz","35202-4444444-4", 24, "0300-4444444", "22-MS-001", 2, 3.6,
                                    "Deep Learning for Medical Imaging", "Dr. Rizwan", "AI / ML");

    // Faculty
    faculty[facultyCount++] = new Faculty("Dr. Rizwan Ahmed", "35202-5555555-5", 45, "0311-1111111",
                                          "FAC-001", "CS", "Associate Professor");
    faculty[facultyCount++] = new Faculty("Ms. Hina Baig",    "35202-6666666-6", 35, "0311-2222222",
                                          "FAC-002", "CS", "Lecturer");

    // Assign courses to faculty
    faculty[0]->assignCourse("CS-501");
    faculty[1]->assignCourse("CS-104L");

    // Courses
    courses[courseCount++] = new Course("CS-104L", "Object-Oriented Programming", 3, faculty[1], 3);
    courses[courseCount++] = new Course("CS-501",  "Advanced Algorithms",          3, faculty[0], 30);
}

// ─── Main ─────────────────────────────────────────────────────────────────
int main() {
    cout << "==========================================" << endl;
    cout << "  Smart Campus Management System (SCMS)  " << endl;
    cout << "  HITEC University Taxila | CS-104L OOP  " << endl;
    cout << "==========================================" << endl;

    seedData();

    Library       lib("data/library_catalog.txt");
    HostelManager hostelMgr("Mr. Hassan");

    // Seed library
    lib.addItem(new Book("B001", "C++ How to Program",          "Deitel",    2020, "978-0-13-524674-4", "CS",    3));
    lib.addItem(new Book("B002", "The C++ Programming Language","Stroustrup",2013, "978-0-321-56384-2", "CS",    2));
    lib.addItem(new Journal("J001","IEEE Transactions on SE",   "IEEE",      2023, "0098-5589",          12, 4));
    lib.saveCatalog();

    // Seed hostel
    HostelBlock* blockA = new HostelBlock("Block A");
    blockA->addRoom(new Room("A101", DOUBLE, 1));
    blockA->addRoom(new Room("A102", TRIPLE, 1));
    blockA->addRoom(new Room("A201", SINGLE, 2));
    hostelMgr.addBlock(blockA);

    int choice = 0;
    do {
        showMainMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: demoModule1();                       break;
            case 2: demoModule2();                       break;
            case 3: demoModule3(lib);                    break;
            case 4: demoModule4();                       break;
            case 5: demoModule5();                       break;
            case 6: demoModule6(lib, hostelMgr);         break;
            case 0: cout << "Exiting SCMS. Goodbye!\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }
    } while (choice != 0);

    cleanupGlobals();
    return 0;
}

void showMainMenu() {
    cout << "\n========== SCMS MAIN MENU ==========" << endl;
    cout << " 1. Module 1 - Person Hierarchy"       << endl;
    cout << " 2. Module 2 - Course & Enrollment"    << endl;
    cout << " 3. Module 3 - Library System"         << endl;
    cout << " 4. Module 4 - Fee & Finance"          << endl;
    cout << " 5. Module 5 - Hostel Management"      << endl;
    cout << " 6. Module 6 - Reports & Utilities"    << endl;
    cout << " 0. Exit"                              << endl;
    cout << "====================================" << endl;
    cout << "Choice: ";
}

// ─── Module 1 Demo ────────────────────────────────────────────────────────
void demoModule1() {
    cout << "\n====== MODULE 1: PERSON HIERARCHY ======" << endl;

    // Runtime polymorphism via base pointer (virtual dispatch)
    Person* people[4];
    people[0] = students[0];
    people[1] = students[3];  // GradStudent (multi-level inheritance)
    people[2] = faculty[0];
    people[3] = new Staff("Ali Raza", "35202-9999999-9", 30, "0300-9999999",
                           "STF-001", "Lab Technician", 45000.0);

    cout << "\n--- Runtime Polymorphism (displayInfo via Person*) ---\n";
    for (int i = 0; i < 4; i++) {
        people[i]->displayInfo();
        cout << endl;
    }

    delete people[3];  // clean up Staff
}

// ─── Module 2 Demo ────────────────────────────────────────────────────────
void demoModule2() {
    cout << "\n====== MODULE 2: COURSE & ENROLLMENT ======" << endl;

    // Display courses using operator<<
    cout << "\n--- Courses (operator<<) ---\n";
    for (int i = 0; i < courseCount; i++)
        cout << *courses[i];

    // Enrollment with exception handling
    cout << "\n--- Enrolling students ---\n";
    try {
        courses[0]->enrollStudent(students[0]);
        courses[0]->enrollStudent(students[1]);
        courses[0]->enrollStudent(students[2]);
        // This 4th enrollment exceeds maxCapacity=3 → exception
        cout << "\nAttempting to enroll 4th student beyond capacity...\n";
        courses[0]->enrollStudent(students[3]);
    } catch (const CapacityExceededException& e) {
        cout << "[CAUGHT] " << e.what() << endl;
        // Add to waiting list instead
        courses[0]->addToWaitingList(students[3]);
    }

    // operator== demo
    Course c1("CS-104L","OOP",3,nullptr);
    Course c2("CS-104L","OOP Lab",1,nullptr);
    Course c3("CS-501", "Algorithms",3,nullptr);
    cout << "\n--- operator== ---\n";
    cout << "CS-104L == CS-104L : " << (c1 == c2 ? "true" : "false") << endl;
    cout << "CS-104L == CS-501  : " << (c1 == c3 ? "true" : "false") << endl;

    // operator+ merge waiting lists
    Course cA("CS-200","DS",3,nullptr,1); cA.addToWaitingList(students[0]);
    Course cB("CS-201","Algo",3,nullptr,1); cB.addToWaitingList(students[1]);
    int mergedSize = cA.getWaitingCount() + cB.getWaitingCount();
    Student** merged = cA + cB;
    cout << "\n--- operator+ (merged waiting lists) ---\n";
    for (int i = 0; i < mergedSize; i++)
        cout << "  " << merged[i]->getName() << endl;
    delete[] merged;

    // Enrollment record
    Enrollment e(students[0], courses[0], "2025-09-01");
    e.setGrade(3.8);
    e.displayEnrollment();
}

// ─── Module 3 Demo ────────────────────────────────────────────────────────
void demoModule3(Library& lib) {
    cout << "\n====== MODULE 3: LIBRARY SYSTEM ======" << endl;
    lib.displayCatalog();

    // Search by title
    cout << "\n--- searchByTitle ---\n";
    LibraryItem* found = lib.searchByTitle("C++ How to Program");
    if (found) {
        cout << "Found: "; found->displayInfo();
    } else {
        cout << "Not found." << endl;
    }

    // Issue and return with overdue exception
    cout << "\n--- Issue & Return (with overdue) ---\n";
    lib.issueItem("21-CS-001", "B001", "2025-09-01", 7);
    lib.returnItem("21-CS-001", "B001", 10);   // 3 days overdue
}

// ─── Module 4 Demo ────────────────────────────────────────────────────────
void demoModule4() {
    cout << "\n====== MODULE 4: FEE & FINANCE ======" << endl;

    // FeeRecord with deep copy
    FeeRecord rec1("21-CS-001", "Ahmed Ali", 25000.0, 8000.0, 0.0);
    rec1.addRemark("Scholarship: 10% discount applied");

    cout << "\n--- Original FeeRecord ---\n";
    rec1.displayRecord();

    // Copy constructor demo
    FeeRecord rec2(rec1);
    rec2.addRemark("Duplicate record for audit");
    cout << "\n--- Copied FeeRecord (deep copy, independent) ---\n";
    rec2.displayRecord();

    // operator-= payment
    cout << "\n--- operator-= payment ---\n";
    try {
        rec1 -= 15000.0;
        rec1 -= 18001.0;  // exceeds balance → exception
    } catch (const InvalidPaymentException& e) {
        cout << "[CAUGHT] " << e.what() << endl;
    }
    rec1.displayRecord();

    // Invoice with static counter
    cout << "\n--- Invoice (static counter) ---\n";
    Invoice inv1("2025-09-15");
    inv1.addItem("Semester Fee", 25000.0);
    inv1.addItem("Hostel Fee",    8000.0);
    inv1.displayInvoice();

    Invoice inv2("2025-09-15");
    inv2.addItem("Library Fine", 150.0);
    inv2.displayInvoice();

    cout << "Total invoices generated: " << Invoice::getInvoiceCount() << endl;
}

// ─── Module 5 Demo ────────────────────────────────────────────────────────
void demoModule5() {
    cout << "\n====== MODULE 5: HOSTEL MANAGEMENT ======" << endl;

    // Fresh hostel manager for demo (to avoid double-free with main's instance)
    HostelManager mgr("Dr. Hostel In-Charge");

    HostelBlock* blk = new HostelBlock("Demo Block");
    blk->addRoom(new Room("D101", DOUBLE, 1));
    blk->addRoom(new Room("D102", SINGLE, 1));
    mgr.addBlock(blk);

    // allocateRoom (Accommodation interface)
    mgr.allocateRoom(students[0], DOUBLE);
    mgr.allocateRoom(students[1], DOUBLE);

    // Room full exception
    cout << "\n--- Attempting to over-fill SINGLE room ---\n";
    mgr.allocateRoom(students[2], SINGLE);
    try {
        mgr.allocateRoom(students[3], SINGLE);  // room is full
    } catch (const RoomFullException& e) {
        cout << "[CAUGHT] " << e.what() << endl;
    }

    // Reportable interface
    mgr.generateOccupancyReport();

    // Vacate
    cout << "\n--- Vacating a student ---\n";
    mgr.vacateRoom(students[0]->getRollNo(), "Demo Block");
    mgr.generateOccupancyReport();
}

// ─── Module 6 Demo ────────────────────────────────────────────────────────
void demoModule6(Library& lib, HostelManager& hostelMgr) {
    cout << "\n====== MODULE 6: REPORTS & UTILITIES ======" << endl;

    // Sort students by GPA then display
    cout << "\n--- Students sorted by GPA (descending) ---\n";
    Reports::sortStudentsByGPA(students, studentCount);
    Reports::printStudentList(students, studentCount);

    // Search
    cout << "\n--- Search student by roll number ---\n";
    Student* found = Reports::findStudentByRollNo(students, studentCount, "21-CS-002");
    if (found) {
        cout << "Found: "; found->displayInfo();
    } else {
        cout << "Not found." << endl;
    }

    // Full campus report (saves to file)
    Reports::generateCampusReport(
        students, studentCount,
        faculty,  facultyCount,
        courses,  courseCount,
        lib, hostelMgr
    );
}

// ─── Cleanup ──────────────────────────────────────────────────────────────
void cleanupGlobals() {
    for (int i = 0; i < studentCount; i++) { delete students[i]; students[i] = nullptr; }
    for (int i = 0; i < facultyCount; i++) { delete faculty[i];  faculty[i]  = nullptr; }
    for (int i = 0; i < courseCount;  i++) { delete courses[i];  courses[i]  = nullptr; }
}
