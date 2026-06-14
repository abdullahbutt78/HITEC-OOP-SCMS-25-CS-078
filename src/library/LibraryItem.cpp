/**
 * @file LibraryItem.cpp
 * @brief Implementation of LibraryItem base class
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Abstract Class, Pure Virtual Function
 */

#include "LibraryItem.h"

LibraryItem::LibraryItem(const string& itemID, const string& title,
                         const string& author, int publicationYear)
    : itemID(itemID), title(title), author(author),
      publicationYear(publicationYear), isCheckedOut(false) {}
