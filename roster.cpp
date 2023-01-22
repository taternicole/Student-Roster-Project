#include <iostream>
#include "roster.h"
#include <string>

using namespace std;

void Roster::parse(string studentData) //parses through each row of the studentDataTable.
{
	int rhs = studentData.find(','); //finds the first comma.
	string stID = studentData.substr(0, rhs); //gets the substring in front of the comma - right hand side (Student ID).

	int onehs = rhs + 1; 
	rhs = studentData.find(',', onehs); //finds the second comma.
	string stFName = studentData.substr(onehs, rhs - onehs); //gets the substring in front of the second comma (First name).

	onehs = rhs + 1;
	rhs = studentData.find(',', onehs); //finds the next comma.
	string stLName = studentData.substr(onehs, rhs - onehs); //gets substring in front of next comma (Last name).

	onehs = rhs + 1;
	rhs = studentData.find(",", onehs); //finds the next comma.
	string stEmail = studentData.substr(onehs, rhs - onehs); //gets substring in front of next comma (Students Email).

	onehs = rhs + 1;
	rhs = studentData.find(",", onehs); //finds the next comma.
	int stAge = stoi(studentData.substr(onehs, rhs - onehs)); //gets string and converts to integer (stoi) in front of next comma (Age).

	onehs = rhs + 1;
	rhs = studentData.find(",", onehs); //finds the next comma.
	int daysInCourse1 = stoi(studentData.substr(onehs, rhs - onehs)); //gets string and converts to integer (stoi) in front of next comma (Days in course 1).

	onehs = rhs + 1;
	rhs = studentData.find(",", onehs); //finds the next comma.
	int daysInCourse2 = stoi(studentData.substr(onehs, rhs - onehs)); //gets string and converts to integer (stoi) in front of next comma (Days in course 2).

	onehs = rhs + 1;
	rhs = studentData.find(",", onehs); //finds the next comma.
	int daysInCourse3 = stoi(studentData.substr(onehs, rhs - onehs)); //gets string and converts to integer (stoi) in front of next comma (Days in course 3).

	onehs = rhs + 1;
	rhs = studentData.find(",", onehs); //finds the next comma.
	DegreeProgram degreeProg = SECURITY; //sets the default degree program to SECURITY.

	if (studentData.at(onehs) == 'S' && studentData.at(onehs + 1) == 'E') degreeProg = SECURITY; //if the degree program begins with letter S and the next letter is E, the degree program is SECURITY.
	else if (studentData.at(onehs) == 'S' && studentData.at(onehs + 1) == 'O') degreeProg = SOFTWARE; //else if the degree program begins with the letter S and the next letter is O, the degree program is SOFTWARE.
	else if (studentData.at(onehs) == 'N') degreeProg = NETWORK; //else if the degree program begins with the letter N, degree program is NETWORK.

	add(stID, stFName, stLName, stEmail, stAge, daysInCourse1, daysInCourse2, daysInCourse3, degreeProg); //sets the add functions parameters
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProg) { //sets instance variables.
	int daysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 }; //an array of daysInCourse
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, daysArray, degreeProg); //constructor

}



void Roster::remove(string studentID) //remove function is called to remove by Student ID
{
	bool studentIDSuccess = false; //if it doesn't successfully find the Student.
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getstudentID() == studentID) {
			studentIDSuccess = true; //if it successfully finds the Student.
			if (i < studentDataTable - 1) {
				Student* fillIn = classRosterArray[i] = classRosterArray[studentDataTable - 1]; //points to fillIn student and swaps places.
				classRosterArray[studentDataTable - 1] = fillIn; 
			}
			Roster::lastIndex--; // hides the last student.
		}
	}
	if (studentIDSuccess)
	{
		this->printAll(); //prints all student ID's found.
	}
	else
		cout << "The student with the ID: " << studentID << " was not found." << endl; //prints if student ID isn't found.
}
void Roster::printAll() //print all function is called
{

	for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print(); //runs through the array and prints all student information.
}

void Roster::printAverageDaysInCourse(string studentID) { //prints student's average number days in the 3 courses.
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getstudentID()==studentID) { //student identified by the studentID parameter
			cout << "Student ID: " << studentID << ", average days in course is: " << endl;
			cout << (classRosterArray[i]->getnumDaysLeft()[0] + classRosterArray[i]->getnumDaysLeft()[1] + classRosterArray[i]->getnumDaysLeft()[2]) / 3 << endl;
			// runs through array and prints average number days in the 3 courses.
		}

		
	}
	cout << endl;
}

void Roster::printInvalidEmails() //prints out invalid emails
{
	bool invalid = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string email = (classRosterArray[i]->getemail()); //gets email.

		if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos)) // if email has a space (" ") it is invalid. This if statement finds that.
		{
			invalid = true;

			cout << email << " - is invalid. " << endl; // if the if statements find an invalid email it prints this.
		}
	}
	if (!invalid) cout << "No valid Student email's" << endl; // if all emails are invalid, this prints.
}

void Roster::printByDegreeProgram(DegreeProgram degreeProg) //prints out students by degree program
{
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getdegreeProgram() == degreeProg) classRosterArray[i]->print();
	}
}

Roster::~Roster() //destructor for Roster is called.
{
	cout << "DONE." << endl << endl;
	
}

