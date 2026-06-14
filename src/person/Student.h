/**
 * @file Student.h
 * @brief Student class derived from Person
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Single Inheritance, Encapsulation, Runtime Polymorphism
 */

#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>
using namespace std;

const int MAX_ENROLLED_COURSES = 10;

class Student : public Person {
protected:
    string rollNo;
    int    semester;
    double gpa;
    string enrolledCourses[MAX_ENROLLED_COURSES];
    int    courseCount;

public:
    Student(const string& name, const string& cnic, int age, const string& contact,
            const string& rollNo, int semester, double gpa);

    void displayInfo() const override;
    string calculateGrade() const;

    void enrollCourse(const string& courseCode);

    // Getters
    string getRollNo()    const { return rollNo;    }
    int    getSemester()  const { return semester;  }
    double getGPA()       const { return gpa;       }
    int    getCourseCount() const { return courseCount; }
    string getEnrolledCourse(int i) const;

    // Setters
    void setRollNo(const string& r)  { rollNo   = r; }
    void setSemester(int s)          { semester = s; }
    void setGPA(double g)            { gpa      = g; }
};

#endif // STUDENT_H
