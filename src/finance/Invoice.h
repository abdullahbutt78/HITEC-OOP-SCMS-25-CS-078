/**
 * @file Invoice.h
 * @brief Invoice class with static invoiceCounter and proper destructor
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Static Members, Destructor, Friend Functions (operator<<)
 */

#ifndef INVOICE_H
#define INVOICE_H

#include <string>
#include <iostream>
using namespace std;

const int MAX_INVOICE_ITEMS = 10;

struct InvoiceItem {
    string description;
    double amount;
};

class Invoice {
private:
    static int invoiceCounter;   // shared across all Invoice objects

    int          invoiceID;
    string       date;
    InvoiceItem* items;          // dynamically allocated array
    int          itemCount;
    int          itemCapacity;
    double       totalAmount;

public:
    Invoice(const string& date, int capacity = MAX_INVOICE_ITEMS);

    // Copy Constructor
    Invoice(const Invoice& other);

    // Destructor: frees dynamically allocated items array
    ~Invoice();

    void addItem(const string& description, double amount);
    void calculateTotal();
    void displayInvoice() const;

    // Getters
    int    getInvoiceID()   const { return invoiceID;   }
    string getDate()        const { return date;        }
    double getTotalAmount() const { return totalAmount; }

    static int getInvoiceCount() { return invoiceCounter; }

    // Friend: operator<<
    friend ostream& operator<<(ostream& os, const Invoice& inv);
};

#endif // INVOICE_H
