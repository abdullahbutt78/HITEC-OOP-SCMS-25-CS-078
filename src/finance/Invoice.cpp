/**
 * @file Invoice.cpp
 * @brief Implementation of Invoice class
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Static Members, Destructor, Friend Functions (operator<<)
 */

#include "Invoice.h"
#include <iostream>
using namespace std;

// Static member definition (must live in .cpp)
int Invoice::invoiceCounter = 0;

Invoice::Invoice(const string& date, int capacity)
    : date(date), itemCount(0), itemCapacity(capacity), totalAmount(0.0) {
    invoiceID = ++invoiceCounter;           // auto-increment
    items     = new InvoiceItem[itemCapacity];
}

// Copy Constructor
Invoice::Invoice(const Invoice& other)
    : invoiceID(other.invoiceID), date(other.date),
      itemCount(other.itemCount), itemCapacity(other.itemCapacity),
      totalAmount(other.totalAmount) {
    items = new InvoiceItem[itemCapacity];  // deep copy
    for (int i = 0; i < itemCount; i++)
        items[i] = other.items[i];
}

// Destructor
Invoice::~Invoice() {
    delete[] items;
}

void Invoice::addItem(const string& description, double amount) {
    if (itemCount < itemCapacity) {
        items[itemCount++] = {description, amount};
        totalAmount += amount;
    } else {
        cout << "Invoice is full. Cannot add: " << description << endl;
    }
}

void Invoice::calculateTotal() {
    totalAmount = 0.0;
    for (int i = 0; i < itemCount; i++)
        totalAmount += items[i].amount;
}

void Invoice::displayInvoice() const {
    cout << *this;
}

ostream& operator<<(ostream& os, const Invoice& inv) {
    os << "========== INVOICE #" << inv.invoiceID << " ==========\n"
       << "Date   : " << inv.date << "\n"
       << "-----------------------------------\n";
    for (int i = 0; i < inv.itemCount; i++) {
        os << "  " << inv.items[i].description
           << "  Rs. " << inv.items[i].amount << "\n";
    }
    os << "-----------------------------------\n"
       << "TOTAL  : Rs. " << inv.totalAmount << "\n"
       << "===================================\n";
    return os;
}
