#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"

using namespace std;


//constructor
classRoster::classRoster()  {	
	this->roster = 0; 
	this->classRosterArray[5];
};


//Add student to classroster 
void classRoster::add(string studentID, string firstname, string lastname, string emailAddress, int age, int daysToCompleteCourse[], string degreeProgram) {
	classRosterArray[this->roster] = new Student(studentID, firstname, lastname, emailAddress, age, daysToCompleteCourse, degreeProgram);
	this->roster++;
};

//print students by degree program
void classRoster::printByDegreeProgram(string degreeProgram) {
	cout << "******* The following students are enrolled in the " << degreeProgram << ":" << endl;
	for (int i = 0; i < this->roster; i++) {
		Student student = *this->classRosterArray[i];
		if (student.getDegreeProgram() == degreeProgram) {
			student.print();
		}
	}
};

//remove student from the roster;
void classRoster::remove(string studentID) {
	for (int i = 0; i < this->roster; i++) {
		Student student = *this->classRosterArray[i];
		if (student.getStudentID() == studentID) {
			cout << endl << "Removing "<< student.getFirstName() << " " << student.getLastName() << " from the roster ..." << endl;
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
void classRoster::printAll() {
	cout << endl << " *************** List of students on the roster  *************" << endl;
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
			cout << endl << "Calculating the average number of days " 
			<< student.getFirstName() << " " << student.getLastName()<< " has been in the program ..."<< endl;
			int numDays= (student.getDaysToCompleteCourse(0) + student.getDaysToCompleteCourse(1) + student.getDaysToCompleteCourse(2));
			int aveDays = numDays / 3;
			cout << "The result is approx. " << aveDays <<" Days." << endl;
		}
	};
};

// check roster for students with invalid email addresses
void classRoster::printInvalidEmails() {
	for (int i = 0; i < this->roster; i++) {
		Student student = *this->classRosterArray[i];
		string email = student.getEmailAddress();
		if ((!email.find("@") && !email.find(".")) || email.find(" ") ) {
			cout << endl << "Student with an ID of " << student.getStudentID()
				<< ", " << student.getFirstName() << " " << student.getLastName()
				<< " has  an invalid email ." << endl;
			cout << "Email address provided: " << student.getEmailAddress() << endl << endl;
			return;
		}
	};
	cout << endl << " No invalid email address found! " << endl;
};

