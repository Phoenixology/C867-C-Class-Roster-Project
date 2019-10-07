
#pragma once
#include <string>
#include "degree.h"

using namespace std;

class Student {
private:
    string studentId;
    string firstName;
    string lastName;
    string email;
    int age;
    int daysInCourse[3];
    const static int daysInCourseArraySize = 3;

public:
    //Constructors
    Student();
    Student(string studentId, string firstName, string lastName, string email, int age, int* daysInCourse);
    ~Student();

    //Mutator
    void setStudentId(string studentId);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDaysInCourse(int* daysInCourse);


    //Accessor
    string getStudentId();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDaysInCourse();
    virtual Degree getDegreeProgram() = 0;
    virtual void print() = 0;
};
