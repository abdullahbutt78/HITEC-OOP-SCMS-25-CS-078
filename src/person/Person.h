/**
 * @file Person.h
 * @brief Abstract base class for all persons in the campus system
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Abstract Class, Pure Virtual Function, Encapsulation
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    string cnic;
    int    age;
    string contact;

public:
    Person(const string& name, const string& cnic, int age, const string& contact);
    virtual ~Person() = default;

    // Pure virtual — makes Person abstract
    virtual void displayInfo() const = 0;

    // Getters
    string getName()    const { return name;    }
    string getCNIC()    const { return cnic;    }
    int    getAge()     const { return age;     }
    string getContact() const { return contact; }

    // Setters
    void setName(const string& n)    { name    = n; }
    void setCNIC(const string& c)    { cnic    = c; }
    void setAge(int a)               { age     = a; }
    void setContact(const string& c) { contact = c; }
};

#endif // PERSON_H
