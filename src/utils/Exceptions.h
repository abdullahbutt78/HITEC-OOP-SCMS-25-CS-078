/**
 * @file Exceptions.h
 * @brief All custom exception classes for SCMS
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Exception Handling, Custom Exception Classes
 */

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>
using namespace std;

// ─── Thrown when a course enrollment exceeds maxCapacity ───────────────────
class CapacityExceededException : public exception {
private:
    string message;
public:
    explicit CapacityExceededException(const string& courseCode)
        : message("Enrollment failed: Course " + courseCode + " has reached maximum capacity.") {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

// ─── Thrown when a library item is returned overdue ────────────────────────
class OverdueException : public exception {
private:
    string message;
    double fineAmount;
public:
    OverdueException(const string& itemTitle, int daysLate, double finePerDay)
        : fineAmount(daysLate * finePerDay) {
        message = "Overdue item: \"" + itemTitle + "\" is " +
                  to_string(daysLate) + " day(s) late. Fine: Rs. " +
                  to_string(fineAmount);
    }

    const char* what() const noexcept override {
        return message.c_str();
    }

    double getFine() const { return fineAmount; }
};

// ─── Thrown when a person record is not found ──────────────────────────────
class PersonNotFoundException : public exception {
private:
    string message;
public:
    explicit PersonNotFoundException(const string& id)
        : message("Person with ID \"" + id + "\" not found.") {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

// ─── Thrown for invalid fee operations ─────────────────────────────────────
class InvalidPaymentException : public exception {
private:
    string message;
public:
    explicit InvalidPaymentException(const string& detail)
        : message("Invalid payment: " + detail) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

// ─── Thrown when a hostel room is full ─────────────────────────────────────
class RoomFullException : public exception {
private:
    string message;
public:
    explicit RoomFullException(const string& roomNo)
        : message("Room " + roomNo + " is already at full occupancy.") {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif // EXCEPTIONS_H
