/**
 * @file Person.cpp
 * @brief Implementation of Person base class
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Abstract Class, Pure Virtual Function, Encapsulation
 */

#include "Person.h"

Person::Person(const string& name, const string& cnic, int age, const string& contact)
    : name(name), cnic(cnic), age(age), contact(contact) {}
