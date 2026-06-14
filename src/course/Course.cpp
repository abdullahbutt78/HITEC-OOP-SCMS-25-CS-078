/**
 * @file Course.cpp
 * @brief Implementation of Course class
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Encapsulation, Operator Overloading (==, <<, +), Friend Functions,
 *               Exception Handling (CapacityExceededException)
 */

#include "Course.h"
#include <iostream>
using namespace std;

Course::Course(const string& courseCode, const string& courseName,
               int creditHours, Faculty* instructor, int maxCapacity)
    : courseCode(courseCode), courseName(courseName),
      creditHours(creditHours), instructor(instructor),
      maxCapacity(maxCapacity), enrolledCount(0), waitingCount(0) {
    for (int i = 0; i < MAX_CAPACITY;     i++) enrolledStudents[i] = nullptr;
    for (int i = 0; i < MAX_WAITING_LIST; i++) waitingList[i]      = nullptr;
}

void Course::enrollStudent(Student* s) {
    if (enrolledCount >= maxCapacity) {
        throw CapacityExceededException(courseCode);
    }
    enrolledStudents[enrolledCount++] = s;
    s->enrollCourse(courseCode);
}

void Course::addToWaitingList(Student* s) {
    if (waitingCount < MAX_WAITING_LIST) {
        waitingList[waitingCount++] = s;
        cout << s->getName() << " added to waiting list for " << courseCode << endl;
    } else {
        cout << "Waiting list for " << courseCode << " is also full." << endl;
    }
}

Student* Course::getWaitingStudent(int i) const {
    if (i >= 0 && i < waitingCount) return waitingList[i];
    return nullptr;
}

// ── Operator Overloads ─────────────────────────────────────────────────────

bool Course::operator==(const Course& other) const {
    return courseCode == other.courseCode;
}

ostream& operator<<(ostream& os, const Course& c) {
    os << "Course   : " << c.courseCode << " - " << c.courseName     << "\n"
       << "Credits  : " << c.creditHours                              << "\n"
       << "Instructor: " << (c.instructor ? c.instructor->getName() : "TBA") << "\n"
       << "Enrolled : " << c.enrolledCount << " / " << c.maxCapacity  << "\n";
    return os;
}

// Merges waiting lists of two courses; caller owns the returned array
Student** Course::operator+(const Course& other) const {
    int totalSize = waitingCount + other.waitingCount;
    if (totalSize == 0) return nullptr;

    Student** merged = new Student*[totalSize];
    for (int i = 0; i < waitingCount;             i++) merged[i]                 = waitingList[i];
    for (int i = 0; i < other.waitingCount;        i++) merged[waitingCount + i]  = other.waitingList[i];
    return merged;
}
