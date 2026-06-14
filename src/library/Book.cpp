/**
 * @file Book.cpp
 * @brief Implementation of Book class
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Inheritance, Runtime Polymorphism
 */

#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(const string& itemID, const string& title, const string& author,
           int publicationYear, const string& isbn, const string& genre, int copies)
    : LibraryItem(itemID, title, author, publicationYear),
      isbn(isbn), genre(genre), copiesAvailable(copies) {}

void Book::checkout() {
    if (copiesAvailable > 0) {
        copiesAvailable--;
        isCheckedOut = (copiesAvailable == 0);
        cout << "Book \"" << title << "\" checked out. Copies left: " << copiesAvailable << endl;
    } else {
        cout << "No copies available for \"" << title << "\"." << endl;
    }
}

void Book::returnItem() {
    copiesAvailable++;
    isCheckedOut = false;
    cout << "Book \"" << title << "\" returned. Copies now: " << copiesAvailable << endl;
}

void Book::displayInfo() const {
    cout << "[Book] " << itemID << " | " << title
         << " | Author: " << author
         << " | Year: "   << publicationYear
         << " | ISBN: "   << isbn
         << " | Genre: "  << genre
         << " | Copies: " << copiesAvailable << endl;
}
