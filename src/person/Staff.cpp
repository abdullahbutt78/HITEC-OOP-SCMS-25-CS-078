/**
 * @file Staff.cpp
 * @brief Implementation of Staff class
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Single Inheritance, Encapsulation, Runtime Polymorphism
 */

#include "Staff.h"
#include <iostream>
using namespace std;

Staff::Staff(const string& name, const string& cnic, int age, const string& contact,
             const string& staffID, const string& role, double salary)
    : Person(name, cnic, age, contact),
      staffID(staffID), role(role), salary(salary) {}

void Staff::displayInfo() const {
    cout << "========== STAFF INFO ==========" << endl;
    cout << "Name    : " << name    << endl;
    cout << "Staff ID: " << staffID << endl;
    cout << "Role    : " << role    << endl;
    cout << "Salary  : Rs. " << salary  << endl;
    cout << "CNIC    : " << cnic    << endl;
    cout << "Contact : " << contact << endl;
    cout << "================================" << endl;
}
