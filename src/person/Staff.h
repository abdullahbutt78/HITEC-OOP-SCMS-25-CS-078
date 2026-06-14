/**
 * @file Staff.h
 * @brief Staff class derived from Person
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Single Inheritance, Encapsulation, Runtime Polymorphism
 */

#ifndef STAFF_H
#define STAFF_H

#include "Person.h"
#include <string>
using namespace std;

class Staff : public Person {
private:
    string staffID;
    string role;
    double salary;

public:
    Staff(const string& name, const string& cnic, int age, const string& contact,
          const string& staffID, const string& role, double salary);

    void displayInfo() const override;

    // Getters
    string getStaffID() const { return staffID; }
    string getRole()    const { return role;    }
    double getSalary()  const { return salary;  }

    // Setters
    void setStaffID(const string& id) { staffID = id;  }
    void setRole(const string& r)     { role    = r;   }
    void setSalary(double s)          { salary  = s;   }
};

#endif // STAFF_H
