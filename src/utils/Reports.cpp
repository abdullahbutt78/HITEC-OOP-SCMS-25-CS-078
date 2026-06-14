/**
 * @file Reports.cpp
 * @brief Implementation of Reports utility class
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Reporting Functions, Sorting, Searching, Memory Management
 */

#include "Reports.h"
#include <iostream>
#include <fstream>
using namespace std;

// ── Sorting ───────────────────────────────────────────────────────────────────

void Reports::sortStudentsByGPA(Student* students[], int count) {
    // Selection sort (descending GPA)
    for (int i = 0; i < count - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < count; j++) {
            if (students[j]->getGPA() > students[maxIdx]->getGPA())
                maxIdx = j;
        }
        if (maxIdx != i) swap(students[i], students[maxIdx]);
    }
}

void Reports::sortStudentsByName(Student* students[], int count) {
    // Bubble sort (ascending name)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j]->getName() > students[j + 1]->getName())
                swap(students[j], students[j + 1]);
        }
    }
}

// ── Searching ─────────────────────────────────────────────────────────────────

Student* Reports::findStudentByRollNo(Student* students[], int count,
                                       const string& rollNo) {
    for (int i = 0; i < count; i++) {
        if (students[i]->getRollNo() == rollNo)
            return students[i];
    }
    return nullptr;
}

// ── Display helpers ───────────────────────────────────────────────────────────

void Reports::printSeparator(int width) {
    for (int i = 0; i < width; i++) cout << '-';
    cout << endl;
}

void Reports::printStudentList(Student* students[], int count) {
    cout << "\n--- STUDENT LIST (" << count << ") ---" << endl;
    printSeparator(60);
    cout << "Roll No    | Name                | Sem | GPA  | Grade" << endl;
    printSeparator(60);
    for (int i = 0; i < count; i++) {
        printf("%-10s | %-20s| %-3d | %-4.2f | %s\n",
               students[i]->getRollNo().c_str(),
               students[i]->getName().c_str(),
               students[i]->getSemester(),
               students[i]->getGPA(),
               students[i]->calculateGrade().c_str());
    }
    printSeparator(60);
}

void Reports::printFacultyList(Faculty* faculty[], int count) {
    cout << "\n--- FACULTY LIST (" << count << ") ---" << endl;
    printSeparator(60);
    for (int i = 0; i < count; i++) {
        cout << faculty[i]->getEmployeeID() << " | "
             << faculty[i]->getName()       << " | "
             << faculty[i]->getDesignation() << " | "
             << faculty[i]->getDepartment() << endl;
    }
    printSeparator(60);
}

void Reports::printCourseList(Course* courses[], int count) {
    cout << "\n--- COURSE LIST (" << count << ") ---" << endl;
    printSeparator(60);
    for (int i = 0; i < count; i++) {
        cout << *courses[i];
    }
    printSeparator(60);
}

// ── Campus-wide report ────────────────────────────────────────────────────────

void Reports::generateCampusReport(
        Student*     students[],  int studentCount,
        Faculty*     faculty[],   int facultyCount,
        Course*      courses[],   int courseCount,
        Library&     library,
        HostelManager& hostelMgr,
        const string& filename) {

    // Print to screen
    cout << "\n" << string(60, '=') << endl;
    cout << "       HITEC UNIVERSITY SMART CAMPUS REPORT" << endl;
    cout << string(60, '=') << endl;

    printStudentList(students, studentCount);
    printFacultyList(faculty,  facultyCount);
    printCourseList(courses,   courseCount);
    library.displayCatalog();
    hostelMgr.generateOccupancyReport();

    // Save to file
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Warning: Could not write campus report to " << filename << endl;
        return;
    }
    file << "HITEC UNIVERSITY - CAMPUS REPORT\n";
    file << string(60, '=') << "\n\n";
    file << "Total Students : " << studentCount << "\n";
    file << "Total Faculty  : " << facultyCount << "\n";
    file << "Total Courses  : " << courseCount  << "\n";
    file << "Library Items  : " << library.getCatalogSize() << "\n";
    file << "\n--- Students (sorted by GPA) ---\n";

    // Make a local copy to sort without modifying the original
    Student** sorted = new Student*[studentCount];
    for (int i = 0; i < studentCount; i++) sorted[i] = students[i];
    sortStudentsByGPA(sorted, studentCount);

    for (int i = 0; i < studentCount; i++) {
        file << sorted[i]->getRollNo() << " | "
             << sorted[i]->getName()   << " | GPA: "
             << sorted[i]->getGPA()    << "\n";
    }
    delete[] sorted;

    file.close();
    cout << "\nCampus report saved to: " << filename << endl;
}
