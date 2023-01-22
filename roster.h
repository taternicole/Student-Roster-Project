#pragma once	
#include <iostream>
#include "student.h"
#include <string>

using namespace std;

class Roster {

public:
	int lastIndex = -1; //returns last index of item if found in the list.
	const static int studentDataTable = 5; //sets constant static integer for studentDataTable of 5. (5 students)
	Student* classRosterArray[studentDataTable]; //Student points to classRosterArray with the array being the studentDataTable.

	void parse(string row); //parses using string delimiter.

	void add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
		//adds all variables.
		void remove(string studentID); //this finds student and removes, which in this project will be student A3.
		void printAll(); //prints all students - student ID, first name, last name, email, days in courses (3 values), and degree program.
		void printAverageDaysInCourse(string studentID); //prints the average number of days in the 3 courses.
		void printInvalidEmails(); //prints students with invalid emails. (must have an "@" or "." with NO spaces.)
		void printByDegreeProgram(DegreeProgram degreeProgram); //prints students out by degree program.

		

		~Roster(); //destructor for Roster
};		

