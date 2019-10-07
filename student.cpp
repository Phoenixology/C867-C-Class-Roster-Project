

#include <iostream>
#include "student.h"
using namespace std;

Student::Student() {
}

Student::Student(string studentId, string firstName, string lastName, string email, int age, int* daysInCourse) {
    this->studentId = studentId;

    this->firstName = firstName;

    this->lastName = lastName;

    this->email = email;

    this->age = age;


    for (int i = 0; i < daysInCourseArraySize; i++) {

        this->daysInCourse[i] = daysInCourse[i];
    }

}

Student::~Student() {

}

void Student::setStudentId(string studentId) {
    this->studentId = studentId;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

void Student::setEmail(string email) {
    this->email = email;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setDaysInCourse(int* daysInCourse) {
    for (int i = 0; i < daysInCourseArraySize; i += 1)
        this->daysInCourse[i] = daysInCourse[i];
}

string Student::getStudentId() {
    return studentId;
}

string Student::getFirstName() {
    return firstName;
}

string Student::getLastName() {
    return lastName;
}

string Student::getEmailAddress() {
    return email;
}

int Student::getAge() {
    return age;
}

int* Student::getDaysInCourse() {
    return daysInCourse;
};



