#include <iostream>
#include "student.h"
#include "degree.h"
#include <iomanip>
#include <string>

using namespace std;

Student::Student() { //this Student constructor doesn't have a parameter. sets default values for each variable.

	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	//sets pointers to variable names

	for (int i = 0; i < numDaysArraySize; i++) this->numDaysLeft[i] = 0;
	this->degreeProgram = DegreeProgram::SECURITY;
	//makes the default degree program  SECURITY

}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int numDaysLeft[], DegreeProgram degreeProgram) //constructor for Student.
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	//sets pointers to variable names
	for (int i = 0; i < numDaysArraySize; i++) this->numDaysLeft[i] = numDaysLeft[i];
	this->degreeProgram = degreeProgram;
}

//Accessors/Getters
string Student::getstudentID()
{
	return this->studentID;
}

string Student::getfirstName()
{
	return this->firstName;
}

string Student::getlastName()
{
	return this->lastName;
}

string Student::getemail()
{
	return this->email;
}

int Student::getage()
{
	return this->age;
}

int* Student::getnumDaysLeft()
{
	return this->numDaysLeft;
}

DegreeProgram Student::getdegreeProgram()
{
	return this->degreeProgram;
}

//Mutators/Setters
void Student::setstudentID(string studentID)
{
	this->studentID = studentID;
}

void Student::setfirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setlastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setemail(string email)
{
	this->email = email;
}

void Student::setage(int age)
{
	this->age = age;
}

void Student::setnumDaysLeft(int numDaysLeft[])
{
	for (int i = 0; i < numDaysArraySize; i++)
		this->numDaysLeft[i] = numDaysLeft[i];
}

void Student::setdegreeProgram(DegreeProgram degreeProgram)
{
	this->degreeProgram = degreeProgram;
}


void Student::print()
{
	cout << studentID << '\t';
	cout << firstName << '\t' << "  ";
	cout << lastName << '\t' << "  ";
	cout << age << '\t';
	cout << numDaysLeft[0] << "," << numDaysLeft[1] << "," << numDaysLeft[2] << '\t';
	cout << degreeProgramStrings[degreeProgram] << "\n";

}
//prints out student info with tabs between to seperate data.
