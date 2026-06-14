/**
 * @file Library.h
 * @brief Library class managing catalog (array of LibraryItem*), File I/O, issued records
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Abstract class arrays, File I/O (fstream), Exception Handling,
 *               Destructor, Array-based collections
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include "LibraryItem.h"
#include "../utils/Exceptions.h"
#include <string>
#include <fstream>
using namespace std;

const int MAX_CATALOG_SIZE  = 100;
const int MAX_ISSUED_ITEMS  = 100;
const double FINE_PER_DAY   = 5.0;   // Rs. 5 per day overdue

struct IssuedRecord {
    string rollNo;
    string itemID;
    string issueDate;
    int    dueDays;   // allowed days before overdue
    int    daysHeld;  // actual days held so far
};

class Library {
private:
    LibraryItem* catalog[MAX_CATALOG_SIZE];
    int          catalogSize;

    IssuedRecord issuedRecords[MAX_ISSUED_ITEMS];
    int          issuedCount;

    string catalogFile;

public:
    explicit Library(const string& catalogFile = "data/library_catalog.txt");
    ~Library();  // frees dynamically allocated items

    void addItem(LibraryItem* item);
    void removeItem(const string& itemID);

    // Search
    LibraryItem* searchByTitle(const string& title) const;
    LibraryItem* searchByID(const string& itemID)   const;

    // Checkout / Return
    void issueItem(const string& rollNo, const string& itemID,
                   const string& issueDate, int dueDays = 14);
    void returnItem(const string& rollNo, const string& itemID, int daysHeld);

    // File I/O
    void saveCatalog()   const;
    void loadCatalog();

    void displayCatalog() const;
    int  getCatalogSize() const { return catalogSize; }
};

#endif // LIBRARY_H
