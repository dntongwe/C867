#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"

using namespace std;


//constructor
Roster::Roster() : roster(0) {
	classRosterArray[5] = {};
};

Roster::~Roster() {

};


//Add student to classroster 
void Roster::add(string studentID, string firstname, string lastname, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string degreeProgram) {
	do {
		int daysToCompleteCourse[3];
		daysToCompleteCourse[0] = daysInCourse1;
		daysToCompleteCourse[1] = daysInCourse2;
		daysToCompleteCourse[2] = daysInCourse3;
		classRosterArray[this->roster] = new Student(studentID, firstname, lastname, emailAddress, age, daysToCompleteCourse, degreeProgram);
	} while (false);
	this->roster++;
};

//print students by degree program
void Roster::printByDegreeProgram(string degreeProgram) {

	cout << "Printing list of students enrolled in the " << degreeProgram << " program :" << endl;
	for (int i = 0; i < this->roster; i++) {
		Student student = *this->classRosterArray[i];
		if (student.getDegreeProgram() == degreeProgram) {
			student.print();
		}
	}
};

//remove student from the roster;
void Roster::remove(string studentID) {
	for (int i = 0; i < this->roster; i++) {
		Student student = *this->classRosterArray[i];
		if (student.getStudentID() == studentID) {
			cout << endl << "Removing student with ID " << student.getStudentID() << ", "  << student.getFirstName() << " " << student.getLastName() << " from the roster ..." << endl;
			student.~Student();
			cout <<"Student Removed!!!" << endl;
			while (i < this->roster-1) {
				classRosterArray[i] = classRosterArray[i+ 1];
				i++;
			}
			roster--;
		}

	}
};

//print students on the roster
void Roster::printAll() {
	cout << endl << "Printing current list of students on the roster ... " << endl;
	for (int i = 0; i < this->roster; i++) {
		Student student = *this->classRosterArray[i];
		student.print();
	};
};


//Print average number of days in the program/course
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < this->roster; i++) {
		Student student = *this->classRosterArray[i];
		if (student.getStudentID() == studentID) {
			cout << endl << "Calculating the average number of days student with ID "  << 
			  student.getStudentID() << ", " << student.getFirstName() << " " 
				<< student.getLastName()<< " spends per course ..."<< endl;
			int numDays= (student.getDaysToCompleteCourse(0) + 
				student.getDaysToCompleteCourse(1) + student.getDaysToCompleteCourse(2));
			int aveDays = numDays / 3;
			cout << "The result is approx. " << aveDays << " Days." << endl << endl << endl;
		}
	};
};

// check roster for students with invalid email addresses
void Roster::printInvalidEmails() {
	cout << endl << "Searching roster for invalid email addresses ...";
	for (int i = 0; i < this->roster; i++) {
		Student student = *this->classRosterArray[i];
		string email = student.getEmailAddress();
		if ((!email.find("@") && !email.find(".")) || email.find(" ") ) {
			cout << endl << "Exception Noted!!! Student with ID " << student.getStudentID()
				<< ", " << student.getFirstName() << " " << student.getLastName()
				<< " has an invalid email." << endl;
			cout << "Address provided: " << student.getEmailAddress() << endl << endl;
			return;
		}
	};
	cout << endl << " No invalid email address found! " << endl;
};

