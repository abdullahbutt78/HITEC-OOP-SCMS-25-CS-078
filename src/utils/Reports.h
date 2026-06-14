/**
 * @file Reports.h
 * @brief Reporting and utility functions for SCMS
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Reporting Functions, Sorting, Searching, Memory Management
 */

#ifndef REPORTS_H
#define REPORTS_H

#include "../person/Student.h"
#include "../person/Faculty.h"
#include "../course/Course.h"
#include "../library/Library.h"
#include "../finance/FeeRecord.h"
#include "../hostel/HostelManager.h"
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

class Reports {
public:
    // ── Sorting ──────────────────────────────────────────────────────────────
    // Sort array of Student* by GPA (descending) using selection sort
    static void sortStudentsByGPA(Student* students[], int count);

    // Sort Student* array by name (ascending)
    static void sortStudentsByName(Student* students[], int count);

    // ── Searching ────────────────────────────────────────────────────────────
    // Find student by roll number; returns nullptr if not found
    static Student* findStudentByRollNo(Student* students[], int count,
                                        const string& rollNo);

    // ── Display helpers ──────────────────────────────────────────────────────
    static void printStudentList(Student* students[], int count);
    static void printFacultyList(Faculty* faculty[], int count);
    static void printCourseList(Course* courses[], int count);

    // ── Campus-wide consolidated text report ─────────────────────────────────
    static void generateCampusReport(
        Student*     students[],  int studentCount,
        Faculty*     faculty[],   int facultyCount,
        Course*      courses[],   int courseCount,
        Library&     library,
        HostelManager& hostelMgr,
        const string& filename = "data/campus_report.txt");

    // Print a horizontal separator line
    static void printSeparator(int width = 50);
};

#endif // REPORTS_H
