/**
 * @file Library.cpp
 * @brief Implementation of Library class with fstream persistence
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 * OOP Concepts: Abstract class arrays, File I/O (fstream), Exception Handling,
 *               Destructor, Array-based collections
 */

#include "Library.h"
#include "Book.h"
#include "Journal.h"
#include <iostream>
#include <sstream>
using namespace std;

Library::Library(const string& catalogFile)
    : catalogSize(0), issuedCount(0), catalogFile(catalogFile) {
    for (int i = 0; i < MAX_CATALOG_SIZE; i++) catalog[i] = nullptr;
}

Library::~Library() {
    // Destructor: free all dynamically allocated LibraryItem objects
    for (int i = 0; i < catalogSize; i++) {
        delete catalog[i];
        catalog[i] = nullptr;
    }
}

void Library::addItem(LibraryItem* item) {
    if (catalogSize < MAX_CATALOG_SIZE) {
        catalog[catalogSize++] = item;
    } else {
        cout << "Library catalog is full. Cannot add: " << item->getTitle() << endl;
    }
}

void Library::removeItem(const string& itemID) {
    for (int i = 0; i < catalogSize; i++) {
        if (catalog[i]->getItemID() == itemID) {
            delete catalog[i];
            // Shift left
            for (int j = i; j < catalogSize - 1; j++)
                catalog[j] = catalog[j + 1];
            catalog[--catalogSize] = nullptr;
            cout << "Item " << itemID << " removed from catalog." << endl;
            return;
        }
    }
    cout << "Item " << itemID << " not found." << endl;
}

LibraryItem* Library::searchByTitle(const string& title) const {
    for (int i = 0; i < catalogSize; i++) {
        if (catalog[i]->getTitle() == title)
            return catalog[i];
    }
    return nullptr;
}

LibraryItem* Library::searchByID(const string& itemID) const {
    for (int i = 0; i < catalogSize; i++) {
        if (catalog[i]->getItemID() == itemID)
            return catalog[i];
    }
    return nullptr;
}

void Library::issueItem(const string& rollNo, const string& itemID,
                        const string& issueDate, int dueDays) {
    LibraryItem* item = searchByID(itemID);
    if (!item) {
        cout << "Item " << itemID << " not found in catalog." << endl;
        return;
    }
    item->checkout();
    if (issuedCount < MAX_ISSUED_ITEMS) {
        issuedRecords[issuedCount++] = {rollNo, itemID, issueDate, dueDays, 0};
        cout << "Item issued to " << rollNo << " on " << issueDate << endl;
    }
}

void Library::returnItem(const string& rollNo, const string& itemID, int daysHeld) {
    for (int i = 0; i < issuedCount; i++) {
        if (issuedRecords[i].rollNo == rollNo && issuedRecords[i].itemID == itemID) {
            int overdueDays = daysHeld - issuedRecords[i].dueDays;
            if (overdueDays > 0) {
                LibraryItem* item = searchByID(itemID);
                string title = item ? item->getTitle() : itemID;
                try {
                    throw OverdueException(title, overdueDays, FINE_PER_DAY);
                } catch (const OverdueException& e) {
                    cout << "[OVERDUE] " << e.what() << endl;
                }
            }
            LibraryItem* item = searchByID(itemID);
            if (item) item->returnItem();

            // Remove from issued records
            for (int j = i; j < issuedCount - 1; j++)
                issuedRecords[j] = issuedRecords[j + 1];
            issuedCount--;
            return;
        }
    }
    cout << "No matching issued record found for " << rollNo << " / " << itemID << endl;
}

void Library::saveCatalog() const {
    ofstream file(catalogFile);
    if (!file.is_open()) {
        cout << "Error: Could not open " << catalogFile << " for writing." << endl;
        return;
    }
    for (int i = 0; i < catalogSize; i++) {
        LibraryItem* item = catalog[i];
        file << item->getType() << "|"
             << item->getItemID()          << "|"
             << item->getTitle()           << "|"
             << item->getAuthor()          << "|"
             << item->getPublicationYear() << "|";

        if (item->getType() == "Book") {
            Book* b = dynamic_cast<Book*>(item);
            file << b->getISBN() << "|" << b->getGenre() << "|" << b->getCopiesAvailable();
        } else if (item->getType() == "Journal") {
            Journal* j = dynamic_cast<Journal*>(item);
            file << j->getISSN() << "|" << j->getVolume() << "|" << j->getIssueNumber();
        }
        file << "\n";
    }
    file.close();
    cout << "Catalog saved to " << catalogFile << endl;
}

void Library::loadCatalog() {
    ifstream file(catalogFile);
    if (!file.is_open()) {
        cout << "Note: " << catalogFile << " not found. Starting with empty catalog." << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        istringstream ss(line);
        string type, itemID, title, author, yearStr;
        getline(ss, type,   '|');
        getline(ss, itemID, '|');
        getline(ss, title,  '|');
        getline(ss, author, '|');
        getline(ss, yearStr,'|');
        int year = stoi(yearStr);

        if (type == "Book") {
            string isbn, genre, copiesStr;
            getline(ss, isbn,     '|');
            getline(ss, genre,    '|');
            getline(ss, copiesStr,'|');
            addItem(new Book(itemID, title, author, year, isbn, genre, stoi(copiesStr)));
        } else if (type == "Journal") {
            string issn, volStr, issueStr;
            getline(ss, issn,    '|');
            getline(ss, volStr,  '|');
            getline(ss, issueStr,'|');
            addItem(new Journal(itemID, title, author, year, issn, stoi(volStr), stoi(issueStr)));
        }
    }
    file.close();
    cout << "Catalog loaded: " << catalogSize << " item(s)." << endl;
}

void Library::displayCatalog() const {
    cout << "\n===== LIBRARY CATALOG =====" << endl;
    if (catalogSize == 0) {
        cout << "  (empty)" << endl;
    }
    for (int i = 0; i < catalogSize; i++) {
        catalog[i]->displayInfo();
    }
    cout << "===========================" << endl;
}
