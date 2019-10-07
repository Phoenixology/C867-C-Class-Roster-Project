#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include "networkStudent.h"
#include "roster.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "student.h"
using namespace std;
using std::cout;
using std::cerr;

Roster::Roster() {

    this->lastIndex = -1;

}

Student* Roster::getStudentAt(int index) {
    return classRosterArray[index];
}

void Roster::parseThenAdd(string row) {

    lastIndex++;
    int rhs = row.find(",");
    string bstudentID = row.substr(0, rhs);


    int lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string bfirstName = row.substr(lhs, rhs - lhs);


    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string blastName = row.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string bemail = row.substr(lhs, rhs - lhs);


    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int bage = stoi(row.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int bd1 = stoi(row.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int bd2 = stoi(row.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    int bd3 = stoi(row.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = row.find(",", lhs);
    string bdegree = row.substr(lhs, rhs - lhs);
    Degree degree = SOFTWARE;
    if (bdegree == "SOFTWARE")
        degree = SOFTWARE;
    else if (bdegree == "SECURITY")
        degree = SECURITY;
    else if (bdegree == "NETWORK")
        degree = NETWORK;



    add(bstudentID, bfirstName, blastName, bemail, bage, bd1, bd2, bd3, degree); 

}

void Roster::add(string studentId, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree) {




    int daysInCourse[3];
    daysInCourse[0] = daysInCourse1;
    daysInCourse[1] = daysInCourse2;
    daysInCourse[2] = daysInCourse3;


    if (degree == NETWORK) {

        classRosterArray[lastIndex] = new NetworkStudent(studentId, firstName, lastName, email, age, daysInCourse, degree);

    }


    if (degree == SECURITY) {

        classRosterArray[lastIndex] = new SecurityStudent(studentId, firstName, lastName, email, age, daysInCourse, degree);
    }


    if (degree == SOFTWARE) {

        classRosterArray[lastIndex] = new SoftwareStudent(studentId, firstName, lastName, email, age, daysInCourse, degree);
    }
}

void Roster::remove(string studentId) {
    std::cout << "Removing student with ID" << studentId << ".." << std::flush;
    for (int i = 0; i < NUMBER_OF_STUDENTS; i += 1) {
        if (classRosterArray[i] == nullptr) {
            std::cout << "ERROR: Student with this ID not found\n";
            break;
        } else if (studentId == classRosterArray[i]->getStudentId()) {
            classRosterArray[i] = nullptr;
            std::cout << "Student removed\n";
        }
    }
}

void Roster::printAll() {
    for (int i = 0; i < 5; i += 1) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
}

void Roster::printAverageDaysInCourse(string studentId) {
    for (int i = 0; i < 5; i += 1) {
        if (studentId == classRosterArray[i]->getStudentId()) {
            int* days = classRosterArray[i]->getDaysInCourse();
            std::cout << studentId << "\t";
            std::cout << setprecision(3) << (((float) days[0] + (float) days[1] + (float) days[2]) / 3) << '\n';
        }
    }
}

void Roster::printByDegreeProgram(Degree degreeProgram) {

    for (int i = 0; i < NUMBER_OF_STUDENTS; i += 1) {
        Student* student = classRosterArray[i];
        if (student->getDegreeProgram() == degreeProgram) {
            student->print();
        }
    }

}

void Roster::printInvalidEmails() {

    cout << "Invalid emails" << endl;
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i]->getEmailAddress().find('@') == string::npos ||
                classRosterArray[i]->getEmailAddress().find('.') == string::npos ||
                classRosterArray[i]->getEmailAddress().find(' ') != string::npos) {
            cout << classRosterArray[i]->getEmailAddress() << endl;
        }
    }

}

int main() {



    std::cout << "Scripting and Programming Applications C867\n";
    std::cout << "Created in C++ by Paul Walton, Id: 000950580\n";

    Roster *classRoster = new Roster();
    Degree degree;
    int numStudents = 5;
    string studentData[5] ={
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Paul,Walton,4pwalton@gmail.com,26,35,44,53,SOFTWARE"
    };

    cout << "Parsing data and adding students:\n";
    for (int i = 0; i < numStudents; i++) {
        classRoster->parseThenAdd(studentData[i]);
    }
    classRoster->printAll();
    classRoster->printInvalidEmails();
    classRoster->printByDegreeProgram(SOFTWARE);


    cout << "Printing average days in course" << endl;
    for (int i = 0; i < 5; i++)
        classRoster->printAverageDaysInCourse(classRoster->getStudentAt(i)->getStudentId());


    classRoster->remove("A3");

    classRoster->remove("A3");

    cout << "DONE.\n";
    cout << "Done. Here is the current student roster:\n";


}




                    
           
            
       