#pragma once
#include <iostream>
#include "degree.h"
#include <string>
#include <iomanip>
#include <array>

using namespace std;

class Student{  //defines class for Student

	public:
		const static int numDaysArraySize = 3;
		//constant static integer of 3 - for the number of average days to complete the courses
	private: 
		string studentID;
		string firstName;			
		string lastName;
		string email;
		int age;
		int numDaysLeft[numDaysArraySize];
		DegreeProgram degreeProgram;
		//these variables are only accessible to the object. 
	public:
		Student();
		Student(string studentID, string firstName, string lastName, string email, int age, int numDaysLeft[], DegreeProgram degreeProgram);
		//these are accessible to everyone including end user.
		
		string getstudentID();
		string getfirstName();
		string getlastName();
		string getemail();
		int getage();
		int* getnumDaysLeft();
		DegreeProgram getdegreeProgram();
		//Accessors/Getters - for each variable.
		
		void setstudentID(string studentID);
		void setfirstName(string firstName);
		void setlastName(string lastName);
		void setemail(string email);
		void setage(int age);
		void setnumDaysLeft(int numDaysLeft[]);
		void setdegreeProgram(DegreeProgram degreeProgram);
		//Mutators/Setters - for each variable




		void print();
		//for printing out student info.

};


