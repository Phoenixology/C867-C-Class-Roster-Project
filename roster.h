#pragma once
#include <string>
#include "softwareStudent.h"
#include "networkStudent.h"
#include "securityStudent.h"
using std::string;

const string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Paul,Walton,4pwalton@gmail.com,26,35,44,53,SOFTWARE",
};
static const unsigned int DATA_COLUMNS = 9;
static const unsigned int NUMBER_OF_STUDENTS = sizeof (studentData) / sizeof (studentData[0]);

class Roster {
private:
    Student* classRosterArray[5];
    int lastIndex;
public:

    void add(

            string studentId,
            string firstName,
            string lastName,
            string emailAddress,
            int age,
            int daysInCourse1,
            int daysInCourse2,
            int daysInCourse3,
            Degree degree
            );
    Student* getStudentAt(int index);
    void parseThenAdd(string row);
    void remove(string studentId);
    void printAll();
    void printAverageDaysInCourse(string StudentId);
    void printInvalidEmails();
    void printByDegreeProgram(Degree program);
    Roster();
    ~Roster();
};