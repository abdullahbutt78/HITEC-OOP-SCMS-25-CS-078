/**
 * @file Book.h
 * @brief Book class derived from LibraryItem
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Inheritance, Runtime Polymorphism
 */

#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"
#include <string>
using namespace std;

class Book : public LibraryItem {
private:
    string isbn;
    string genre;
    int    copiesAvailable;

public:
    Book(const string& itemID, const string& title, const string& author,
         int publicationYear, const string& isbn, const string& genre, int copies);

    void checkout()     override;
    void returnItem()   override;
    void displayInfo()  const override;
    string getType()    const override { return "Book"; }

    // Getters
    string getISBN()           const { return isbn;            }
    string getGenre()          const { return genre;           }
    int    getCopiesAvailable() const { return copiesAvailable; }

    // Setters
    void setISBN(const string& i)  { isbn  = i; }
    void setGenre(const string& g) { genre = g; }
    void setCopies(int c)          { copiesAvailable = c; }
};

#endif // BOOK_H
