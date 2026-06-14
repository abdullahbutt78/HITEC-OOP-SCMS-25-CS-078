/**
 * @file Faculty.h
 * @brief Faculty class derived from Person
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Single Inheritance, Encapsulation, Runtime Polymorphism
 */

#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"
#include <string>
using namespace std;

const int MAX_ASSIGNED_COURSES = 5;

class Faculty : public Person {
private:
    string employeeID;
    string department;
    string designation;
    string assignedCourses[MAX_ASSIGNED_COURSES];
    int    courseCount;

public:
    Faculty(const string& name, const string& cnic, int age, const string& contact,
            const string& employeeID, const string& department, const string& designation);

    void displayInfo() const override;

    void assignCourse(const string& courseCode);

    // Getters
    string getEmployeeID()  const { return employeeID;  }
    string getDepartment()  const { return department;  }
    string getDesignation() const { return designation; }
    int    getCourseCount() const { return courseCount; }
    string getAssignedCourse(int i) const;

    // Setters
    void setEmployeeID(const string& id)  { employeeID  = id; }
    void setDepartment(const string& d)   { department  = d;  }
    void setDesignation(const string& d)  { designation = d;  }
};

#endif // FACULTY_H
