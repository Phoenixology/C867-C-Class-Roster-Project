
#pragma once
#include "student.h"

class NetworkStudent : public Student {
private:
    Degree degree;
public:
    Degree getDegreeProgram();
    void print();
    NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int* daysInCourse, Degree degreeProgram);
};
