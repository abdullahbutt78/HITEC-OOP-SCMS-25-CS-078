/**
 * @file FeeRecord.cpp
 * @brief Implementation of FeeRecord with deep copy and operator-=
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Copy Constructor, Copy Assignment (Deep Copy), Operator Overloading (-=)
 */

#include "FeeRecord.h"
#include <iostream>
using namespace std;

FeeRecord::FeeRecord(const string& rollNo, const string& name,
                     double semFee, double hostelFee, double libFine)
    : studentRollNo(rollNo), studentName(name),
      semesterFee(semFee), hostelFee(hostelFee), libraryFine(libFine),
      totalPaid(0.0), remarkCount(0), remarkCapacity(5) {
    remarks = new string[remarkCapacity];
    calculateBalance();
}

// ── Deep Copy Constructor ───────────────────────────────────────────────────
FeeRecord::FeeRecord(const FeeRecord& other)
    : studentRollNo(other.studentRollNo), studentName(other.studentName),
      semesterFee(other.semesterFee),     hostelFee(other.hostelFee),
      libraryFine(other.libraryFine),     totalPaid(other.totalPaid),
      balance(other.balance),             remarkCount(other.remarkCount),
      remarkCapacity(other.remarkCapacity) {
    // Deep copy: allocate new array, don't share the pointer
    remarks = new string[remarkCapacity];
    for (int i = 0; i < remarkCount; i++)
        remarks[i] = other.remarks[i];
}

// ── Deep Copy Assignment ────────────────────────────────────────────────────
FeeRecord& FeeRecord::operator=(const FeeRecord& other) {
    if (this == &other) return *this;  // self-assignment guard

    delete[] remarks;                  // free existing memory

    studentRollNo   = other.studentRollNo;
    studentName     = other.studentName;
    semesterFee     = other.semesterFee;
    hostelFee       = other.hostelFee;
    libraryFine     = other.libraryFine;
    totalPaid       = other.totalPaid;
    balance         = other.balance;
    remarkCount     = other.remarkCount;
    remarkCapacity  = other.remarkCapacity;

    remarks = new string[remarkCapacity];
    for (int i = 0; i < remarkCount; i++)
        remarks[i] = other.remarks[i];

    return *this;
}

// ── Destructor ──────────────────────────────────────────────────────────────
FeeRecord::~FeeRecord() {
    delete[] remarks;
}

// ── operator-= : record a payment ──────────────────────────────────────────
FeeRecord& FeeRecord::operator-=(double payment) {
    if (payment <= 0) {
        throw InvalidPaymentException("Payment amount must be positive.");
    }
    if (payment > balance) {
        throw InvalidPaymentException("Payment Rs." + to_string(payment) +
                                      " exceeds outstanding balance Rs." + to_string(balance));
    }
    totalPaid += payment;
    balance   -= payment;
    cout << "Payment of Rs. " << payment << " recorded for " << studentName
         << ". Remaining balance: Rs. " << balance << endl;
    return *this;
}

void FeeRecord::addRemark(const string& remark) {
    if (remarkCount >= remarkCapacity) {
        // Grow the array (dynamic resize)
        remarkCapacity *= 2;
        string* newRemarks = new string[remarkCapacity];
        for (int i = 0; i < remarkCount; i++) newRemarks[i] = remarks[i];
        delete[] remarks;
        remarks = newRemarks;
    }
    remarks[remarkCount++] = remark;
}

void FeeRecord::calculateBalance() {
    balance = (semesterFee + hostelFee + libraryFine) - totalPaid;
}

void FeeRecord::displayRecord() const {
    cout << "====== FEE RECORD ======" << endl;
    cout << "Roll No      : " << studentRollNo << endl;
    cout << "Name         : " << studentName   << endl;
    cout << "Semester Fee : Rs. " << semesterFee  << endl;
    cout << "Hostel Fee   : Rs. " << hostelFee    << endl;
    cout << "Library Fine : Rs. " << libraryFine  << endl;
    cout << "Total Paid   : Rs. " << totalPaid    << endl;
    cout << "Balance Due  : Rs. " << balance      << endl;
    if (remarkCount > 0) {
        cout << "Remarks      : " << endl;
        for (int i = 0; i < remarkCount; i++)
            cout << "  - " << remarks[i] << endl;
    }
    cout << "========================" << endl;
}
