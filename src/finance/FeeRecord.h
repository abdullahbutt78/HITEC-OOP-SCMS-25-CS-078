/**
 * @file FeeRecord.h
 * @brief FeeRecord class with copy constructor, copy assignment, and operator-=
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Copy Constructor, Copy Assignment (Deep Copy), Operator Overloading (-=)
 */

#ifndef FEERECORD_H
#define FEERECORD_H

#include <string>
#include <iostream>
#include "../utils/Exceptions.h"
using namespace std;

class FeeRecord {
private:
    string studentRollNo;
    string studentName;
    double semesterFee;
    double hostelFee;
    double libraryFine;
    double totalPaid;
    double balance;

    // Dynamically allocated remarks array (to demonstrate deep copy)
    string* remarks;
    int     remarkCount;
    int     remarkCapacity;

public:
    FeeRecord(const string& rollNo, const string& name,
              double semFee, double hostelFee = 0.0, double libFine = 0.0);

    // Copy Constructor (deep copy)
    FeeRecord(const FeeRecord& other);

    // Copy Assignment Operator (deep copy)
    FeeRecord& operator=(const FeeRecord& other);

    // Destructor
    ~FeeRecord();

    // operator-= : record a payment
    FeeRecord& operator-=(double payment);

    void addRemark(const string& remark);
    void calculateBalance();
    void displayRecord() const;

    // Getters
    string getRollNo()      const { return studentRollNo; }
    string getName()        const { return studentName;   }
    double getSemesterFee() const { return semesterFee;   }
    double getHostelFee()   const { return hostelFee;     }
    double getLibraryFine() const { return libraryFine;   }
    double getTotalPaid()   const { return totalPaid;     }
    double getBalance()     const { return balance;       }

    // Setters
    void setLibraryFine(double f) { libraryFine = f; calculateBalance(); }
    void setHostelFee(double h)   { hostelFee   = h; calculateBalance(); }
};

#endif // FEERECORD_H
