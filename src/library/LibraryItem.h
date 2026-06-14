/**
 * @file LibraryItem.h
 * @brief Abstract base class for all library items
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Abstract Class, Pure Virtual Function
 */

#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <string>
#include <iostream>
using namespace std;

class LibraryItem {
protected:
    string itemID;
    string title;
    string author;
    int    publicationYear;
    bool   isCheckedOut;

public:
    LibraryItem(const string& itemID, const string& title,
                const string& author, int publicationYear);
    virtual ~LibraryItem() = default;

    // Pure virtual — makes LibraryItem abstract
    virtual void checkout() = 0;
    virtual void returnItem() = 0;
    virtual void displayInfo() const = 0;
    virtual string getType() const = 0;

    // Getters
    string getItemID()          const { return itemID;          }
    string getTitle()           const { return title;           }
    string getAuthor()          const { return author;          }
    int    getPublicationYear() const { return publicationYear; }
    bool   getIsCheckedOut()    const { return isCheckedOut;    }

    // Setters
    void setTitle(const string& t)  { title  = t; }
    void setAuthor(const string& a) { author = a; }
};

#endif // LIBRARYITEM_H
