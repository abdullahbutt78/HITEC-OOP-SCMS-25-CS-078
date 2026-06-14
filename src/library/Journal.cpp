/**
 * @file Journal.cpp
 * @brief Implementation of Journal class
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Inheritance, Runtime Polymorphism
 */

#include "Journal.h"
#include <iostream>
using namespace std;

Journal::Journal(const string& itemID, const string& title, const string& author,
                 int publicationYear, const string& issn, int volume, int issueNumber)
    : LibraryItem(itemID, title, author, publicationYear),
      issn(issn), volume(volume), issueNumber(issueNumber) {}

void Journal::checkout() {
    if (!isCheckedOut) {
        isCheckedOut = true;
        cout << "Journal \"" << title << "\" checked out." << endl;
    } else {
        cout << "Journal \"" << title << "\" is already checked out." << endl;
    }
}

void Journal::returnItem() {
    isCheckedOut = false;
    cout << "Journal \"" << title << "\" returned." << endl;
}

void Journal::displayInfo() const {
    cout << "[Journal] " << itemID << " | " << title
         << " | Author: " << author
         << " | Year: "   << publicationYear
         << " | ISSN: "   << issn
         << " | Vol: "    << volume
         << " | Issue: "  << issueNumber
         << " | Status: " << (isCheckedOut ? "Checked Out" : "Available") << endl;
}
