/**
 * @file GradStudent.cpp
 * @brief Implementation of GradStudent (multi-level inheritance)
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Multi-level Inheritance
 */

#include "GradStudent.h"
#include <iostream>
using namespace std;

GradStudent::GradStudent(const string& name, const string& cnic, int age, const string& contact,
                         const string& rollNo, int semester, double gpa,
                         const string& thesisTitle, const string& supervisor, const string& researchArea)
    : Student(name, cnic, age, contact, rollNo, semester, gpa),
      thesisTitle(thesisTitle), supervisor(supervisor), researchArea(researchArea) {}

void GradStudent::displayInfo() const {
    Student::displayInfo();
    cout << "--- Graduate Details ---" << endl;
    cout << "Thesis    : " << thesisTitle  << endl;
    cout << "Supervisor: " << supervisor   << endl;
    cout << "Research  : " << researchArea << endl;
    cout << "------------------------" << endl;
}
