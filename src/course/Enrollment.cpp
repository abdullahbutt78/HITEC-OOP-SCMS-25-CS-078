/**
 * @file Enrollment.cpp
 * @brief Implementation of Enrollment class
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Encapsulation, Aggregation
 */

#include "Enrollment.h"
#include <iostream>
using namespace std;

Enrollment::Enrollment(Student* student, Course* course, const string& enrollmentDate)
    : student(student), course(course), enrollmentDate(enrollmentDate), grade(0.0) {}

void Enrollment::displayEnrollment() const {
    cout << "Enrollment Record:" << endl;
    cout << "  Student : " << (student ? student->getName()    : "N/A") << endl;
    cout << "  Course  : " << (course  ? course->getCourseCode(): "N/A") << endl;
    cout << "  Date    : " << enrollmentDate << endl;
    cout << "  Grade   : " << grade          << endl;
}
