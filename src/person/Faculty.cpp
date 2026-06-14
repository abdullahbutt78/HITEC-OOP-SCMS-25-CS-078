/**
 * @file Faculty.cpp
 * @brief Implementation of Faculty class
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Single Inheritance, Encapsulation, Runtime Polymorphism
 */

#include "Faculty.h"
#include <iostream>
using namespace std;

Faculty::Faculty(const string& name, const string& cnic, int age, const string& contact,
                 const string& employeeID, const string& department, const string& designation)
    : Person(name, cnic, age, contact),
      employeeID(employeeID), department(department), designation(designation), courseCount(0) {}

void Faculty::displayInfo() const {
    cout << "========== FACULTY INFO ==========" << endl;
    cout << "Name        : " << name        << endl;
    cout << "Employee ID : " << employeeID  << endl;
    cout << "Department  : " << department  << endl;
    cout << "Designation : " << designation << endl;
    cout << "CNIC        : " << cnic        << endl;
    cout << "Contact     : " << contact     << endl;
    cout << "Courses     : ";
    for (int i = 0; i < courseCount; i++) {
        cout << assignedCourses[i];
        if (i < courseCount - 1) cout << ", ";
    }
    cout << endl;
    cout << "==================================" << endl;
}

void Faculty::assignCourse(const string& courseCode) {
    if (courseCount < MAX_ASSIGNED_COURSES) {
        assignedCourses[courseCount++] = courseCode;
    } else {
        cout << "Warning: " << name << " already has max courses assigned." << endl;
    }
}

string Faculty::getAssignedCourse(int i) const {
    if (i >= 0 && i < courseCount)
        return assignedCourses[i];
    return "";
}
