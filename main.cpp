#include <iostream>
#include "roster.h"
#include <string>
using namespace std;

int main() {

	cout << "C867-Scripting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 002308905" << endl;
	cout << "Taylor Fillers" << endl << endl;
	//heading - my class, programming language, student ID, and name.


	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Taylor,Fillers,tfille3@wgu.edu,23,14,31,30,SOFTWARE"
	};
	//string of student data along with A5 being filled out with my personal information.

	Roster classRoster;
	//creates instance of Roster class

	const int studentDataTable = 5;
	//sets constant integer of 5 for the student data table.

	for (int i = 0; i < studentDataTable; i++) classRoster.parse(studentData[i]);
	cout << "Displaying all students:" << endl;
	classRoster.printAll();
	cout << endl;
	//displays all students of all Degree Program's.

	cout << "Displaying invalid emails:\n" << endl;
	classRoster.printInvalidEmails();
	cout << std::endl;
	//displays students with invalid emails.

	for (int i = 0; i < 1; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getstudentID());
	}
	//displays students average days to complete 3 courses.

	for (int i = 0; i < 3; i++) {
		cout << "Showing students in degree program: " << degreeProgramStrings[i] << endl << endl;
		classRoster.printByDegreeProgram((DegreeProgram)i);
		cout << endl;
	}
	//displays students by their degree program.
	
	cout << "Removing A3:" << endl;
	cout << endl;
	classRoster.remove("A3");
	cout << endl;
	//removes student with ID A3 from the roster.
	
	cout << "Removing A3 again" << endl << endl;
	classRoster.remove("A3");
	//removes student with ID A3 again from the roster.
	




	



	return 0;
	//returns nothing.
}