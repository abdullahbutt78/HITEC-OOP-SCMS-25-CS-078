/**
 * @file Enrollment.h
 * @brief Enrollment class linking Student and Course
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Encapsulation, Aggregation
 */

#ifndef ENROLLMENT_H
#define ENROLLMENT_H

#include "../person/Student.h"
#include "Course.h"
#include <string>
using namespace std;

class Enrollment {
private:
    Student* student;
    Course*  course;
    string   enrollmentDate;
    double   grade;

public:
    Enrollment(Student* student, Course* course, const string& enrollmentDate);

    // Getters
    Student* getStudent()        const { return student;        }
    Course*  getCourse()         const { return course;         }
    string   getEnrollmentDate() const { return enrollmentDate; }
    double   getGrade()          const { return grade;          }

    // Setter
    void setGrade(double g) { grade = g; }

    void displayEnrollment() const;
};

#endif // ENROLLMENT_H
