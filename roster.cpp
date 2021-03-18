#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"

using namespace std;


//constructor
classRoster::classRoster() : roster(0) {	
	this->classRosterArray[5]; // Initialize member;
};

void setclassRosterArray() {
	//this->classRosterArray[5];
	return;
};

void classRoster::add(string studentID, string firstname, string lastname, string emailAddress, int age, int daysToCompleteCourse[], string degreeProgram) {
	classRosterArray[this->roster] = new Student(studentID, firstname, lastname, emailAddress, age, daysToCompleteCourse, degreeProgram);
	this->roster++;
	cout << " The student has been added to the roster. " << endl;
};


void classRoster::remove(string studentID) {
	for (int i = 0; i < this->roster; i++) {
		Student student = *this->classRosterArray[i];
		if (student.getStudentID() == studentID) {
			delete &student;
			this->roster--;
		}
	}
};

void classRoster::printAll() {
	cout << "Print out of the student roster" << endl;
	for (int i = 0; i < this->roster; i++) {
		Student student = *this->classRosterArray[i];
		cout << student.getFirstName() << " " << student.getLastName() << endl;
		student.print();
	};

};

void classRoster::printAverageDaysInCourse(string studentID) {
	cout << "Print out of average days to complete course" << endl;
	for (int i = 0; i < this->roster; i++) {
		Student student = *this->classRosterArray[i];
		if (student.getStudentID() == studentID) {
			int aveDays = (student.getDaysToCompleteCourse(0) + student.getDaysToCompleteCourse(1) + student.getDaysToCompleteCourse(2)) / 3;
			cout << "Average number of days: " << aveDays << endl << endl;
		}
	};
};

void classRoster::printInvalidEmails() {
	for (int i = 0; i < this->roster; i++) {
		Student student = *this->classRosterArray[i];
		string email = student.getEmailAddress();
		if ((!email.find("@") && email.find(".")) || email.find(" ") ) {
			//cout << endl << "Print invalid emails out of the student roster" << endl;
			cout << endl << student.getStudentID() << " has  an invalid email ." << endl;
			cout << "Email address provided: " << student.getEmailAddress() << endl << endl << endl << endl;
			return;
		}
	};
	cout << "There are no invalid email addresses on record" << endl;
};

//int getDegree();
void classRoster::printByDegreeProgram(string degreeProgram) {
	cout << endl <<  "Students majoring in " << degreeProgram << endl;
	for (int i = 0; i < this->roster; i++) {
		Student student = *this->classRosterArray[i];
		if (degreeProgram == "SOFTWARE"  &&  Degree::SOFTWARE) {
			student.print();
		}
		else if (degreeProgram == "NETWORK" && Degree::NETWORK) {
			student.print();
		}
		else {
			student.print();
		}
	}
};
