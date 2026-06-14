/**
 * @file Student.cpp
 * @brief Implementation of the Student class
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Single Inheritance, Encapsulation, Runtime Polymorphism
 */

#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(const string& name, const string& cnic, int age, const string& contact,
                 const string& rollNo, int semester, double gpa)
    : Person(name, cnic, age, contact),
      rollNo(rollNo), semester(semester), gpa(gpa), courseCount(0) {}

void Student::displayInfo() const {
    cout << "========== STUDENT INFO ==========" << endl;
    cout << "Name     : " << name     << endl;
    cout << "Roll No  : " << rollNo   << endl;
    cout << "CNIC     : " << cnic     << endl;
    cout << "Age      : " << age      << endl;
    cout << "Contact  : " << contact  << endl;
    cout << "Semester : " << semester << endl;
    cout << "GPA      : " << gpa      << endl;
    cout << "Grade    : " << calculateGrade() << endl;
    cout << "Courses  : ";
    for (int i = 0; i < courseCount; i++) {
        cout << enrolledCourses[i];
        if (i < courseCount - 1) cout << ", ";
    }
    cout << endl;
    cout << "==================================" << endl;
}

string Student::calculateGrade() const {
    if (gpa >= 3.7) return "A";
    if (gpa >= 3.3) return "A-";
    if (gpa >= 3.0) return "B+";
    if (gpa >= 2.7) return "B";
    if (gpa >= 2.3) return "B-";
    if (gpa >= 2.0) return "C+";
    if (gpa >= 1.7) return "C";
    if (gpa >= 1.0) return "D";
    return "F";
}

void Student::enrollCourse(const string& courseCode) {
    if (courseCount < MAX_ENROLLED_COURSES) {
        enrolledCourses[courseCount++] = courseCode;
    } else {
        cout << "Warning: Maximum course limit reached for " << name << endl;
    }
}

string Student::getEnrolledCourse(int i) const {
    if (i >= 0 && i < courseCount)
        return enrolledCourses[i];
    return "";
}
