#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"

using namespace std;


//constructor
classRoster::classRoster() {	
	this->roster = 0; 
	this->classRosterArray[5];
};


//Add student to classroster 
void classRoster::add(string studentID, string firstname, string lastname, string emailAddress, int age, int daysToCompleteCourse[], string degreeProgram) {
	classRosterArray[this->roster] = new Student(studentID, firstname, lastname, emailAddress, age, daysToCompleteCourse, degreeProgram);
	this->roster++;
};

//remove student from the roster;
void classRoster::remove(string studentID) {
	for (int i = 0; i < this->roster; i++) {
		Student student = *this->classRosterArray[i];
		if (student.getStudentID() == studentID) {
			student.~Student();
			while (i < this->roster-1) {
				classRosterArray[i] = classRosterArray[i+ 1];
				i++;
			}
			roster--;
		}

	}
};

//print students on the roster
void classRoster::printAll() {
	for (int i = 0; i < this->roster; i++) {
		Student student = *this->classRosterArray[i];
		student.print();
	};
};


//Print average number of days in the program/course
void classRoster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < this->roster; i++) {
		Student student = *this->classRosterArray[i];
		if (student.getStudentID() == studentID) {
			int aveDays = (student.getDaysToCompleteCourse(0) + student.getDaysToCompleteCourse(1) + student.getDaysToCompleteCourse(2)) / 3;
			cout << "Average number of days: " << aveDays << endl << endl;
		}
	};
};

// check roster for students with invalid email addresses
void classRoster::printInvalidEmails() {
	for (int i = 0; i < this->roster; i++) {
		Student student = *this->classRosterArray[i];
		string email = student.getEmailAddress();
		if ((!email.find("@") && !email.find(".")) || email.find(" ") ) {
			cout << student.getStudentID() << " has  an invalid email ." << endl;
			cout << "Email address provided: " << student.getEmailAddress() << endl << endl;
			return;
		}
	};
	cout << " No invalid email address found! " << endl;
};

