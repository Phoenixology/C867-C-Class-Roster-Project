#pragma once
#include "student.h"

class SoftwareStudent : public Student {
private:
    Degree degree;
public:
    Degree getDegreeProgram();
    void print();
    SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int* daysInCourse, Degree degreeProgram);
};