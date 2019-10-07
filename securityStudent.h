#pragma once
#include "student.h"

class SecurityStudent : public Student {
private:
    Degree degree;
public:
    Degree getDegreeProgram();
    void print();
    SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int* daysInCourse, Degree degreeProgram);
};