/**
 * @file Journal.h
 * @brief Journal class derived from LibraryItem
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Inheritance, Runtime Polymorphism
 */

#ifndef JOURNAL_H
#define JOURNAL_H

#include "LibraryItem.h"
#include <string>
using namespace std;

class Journal : public LibraryItem {
private:
    string issn;
    int    volume;
    int    issueNumber;

public:
    Journal(const string& itemID, const string& title, const string& author,
            int publicationYear, const string& issn, int volume, int issueNumber);

    void checkout()     override;
    void returnItem()   override;
    void displayInfo()  const override;
    string getType()    const override { return "Journal"; }

    // Getters
    string getISSN()        const { return issn;        }
    int    getVolume()      const { return volume;      }
    int    getIssueNumber() const { return issueNumber; }
};

#endif // JOURNAL_H
