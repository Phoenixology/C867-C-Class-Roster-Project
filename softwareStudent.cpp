#include <iostream>

#include "softwareStudent.h"

using namespace std;

SoftwareStudent::SoftwareStudent(string studentID,string firstName,string lastName,string emailAddress,int age,int* daysInCourse,Degree  degreeProgram)
 : Student(studentID, firstName, lastName, emailAddress, age, daysInCourse)
{
    degree = degreeProgram;
    

}

Degree SoftwareStudent::getDegreeProgram()
{
    return degree;
}
void SoftwareStudent::print()
{
	std::cout << getStudentId();
	std::cout << "\tFirst name: " << getFirstName();
	std::cout << "\tLast name: " << getLastName();
	std::cout << "\tAge: " << getAge();
	int* days = getDaysInCourse();
	std::cout << "\t Days in course: " << days[0] << "," << days[1] << "," << days[2];
        cout << "\t SOFTWARE" << "\n";
}
	
	