/**
 * @file GradStudent.h
 * @brief GradStudent class: multi-level inheritance (GradStudent -> Student -> Person)
 * @author Abdullah Butt | Roll No: 25-CS-078
 * @course CS-104L: Object-Oriented Programming
 * @inst HITEC University Taxila
 * @date June 2026
 *
 * OOP Concepts: Multi-level Inheritance
 */

#ifndef GRADSTUDENT_H
#define GRADSTUDENT_H

#include "Student.h"
#include <string>
using namespace std;

class GradStudent : public Student {
private:
    string thesisTitle;
    string supervisor;
    string researchArea;

public:
    GradStudent(const string& name, const string& cnic, int age, const string& contact,
                const string& rollNo, int semester, double gpa,
                const string& thesisTitle, const string& supervisor, const string& researchArea);

    void displayInfo() const override;

    // Getters
    string getThesisTitle()  const { return thesisTitle;  }
    string getSupervisor()   const { return supervisor;   }
    string getResearchArea() const { return researchArea; }

    // Setters
    void setThesisTitle(const string& t)  { thesisTitle  = t; }
    void setSupervisor(const string& s)   { supervisor   = s; }
    void setResearchArea(const string& r) { researchArea = r; }
};

#endif // GRADSTUDENT_H
