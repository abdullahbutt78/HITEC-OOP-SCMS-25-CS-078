/**
 * @file Course.h
 * @brief Course class with operator overloading
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Encapsulation, Operator Overloading (==, <<, +), Friend Functions,
 *               Exception Handling (CapacityExceededException)
 */

#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>
#include "../person/Student.h"
#include "../person/Faculty.h"
#include "../utils/Exceptions.h"
using namespace std;

const int MAX_CAPACITY      = 50;
const int MAX_WAITING_LIST  = 20;

class Course {
private:
    string courseCode;
    string courseName;
    int    creditHours;
    Faculty* instructor;        // aggregation — Course holds a Faculty*
    int    maxCapacity;
    int    enrolledCount;
    Student* enrolledStudents[MAX_CAPACITY];

    // Waiting list
    Student* waitingList[MAX_WAITING_LIST];
    int      waitingCount;

public:
    Course(const string& courseCode, const string& courseName,
           int creditHours, Faculty* instructor, int maxCapacity = 30);

    // Enroll a student; throws CapacityExceededException if full
    void enrollStudent(Student* s);

    // Add student to waiting list
    void addToWaitingList(Student* s);

    // Getters
    string   getCourseCode()    const { return courseCode;    }
    string   getCourseName()    const { return courseName;    }
    int      getCreditHours()   const { return creditHours;   }
    Faculty* getInstructor()    const { return instructor;    }
    int      getMaxCapacity()   const { return maxCapacity;   }
    int      getEnrolledCount() const { return enrolledCount; }
    int      getWaitingCount()  const { return waitingCount;  }
    Student* getWaitingStudent(int i) const;

    // Setters
    void setCourseCode(const string& c)  { courseCode  = c; }
    void setCourseName(const string& n)  { courseName  = n; }
    void setCreditHours(int ch)          { creditHours = ch; }
    void setInstructor(Faculty* f)       { instructor  = f; }
    void setMaxCapacity(int m)           { maxCapacity = m; }

    // ── Operator Overloads ──────────────────────────────────────────────────
    // == : compare by courseCode
    bool operator==(const Course& other) const;

    // << : stream insertion (friend)
    friend ostream& operator<<(ostream& os, const Course& c);

    // + : merge two waiting lists → returns new array (caller must delete[])
    Student** operator+(const Course& other) const;
};

#endif // COURSE_H
