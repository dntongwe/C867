#include <iostream>
#include <string>
#include <vector>
#include<sstream>
#include "student.h"
#include "degree.h"
#include "roster.h"
using namespace std;

int getDegree(string degree); // converts degree program into an enum;


int main() {

	cout << " **** **** BEGIN *Print Course title and Student ID **********************" << endl;
	cout << " ********* Course Title: Scripting and Programming - Applications – C867 ****" << endl;
	cout << " ********* Student ID: #002751555                                                     ****"<< endl;
	cout << " ********* END ***************************************************" << endl << endl << endl << endl;


	// Declare variable holding studentData
	string studentData[5] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Dieudonne,Ntongwe,test@email.com,43,20,25,33,SOFTWARE"
	};

	classRoster roster;


	//parse Student Data

	for (int i = 0; i < 5; i++) {
		vector<string> result;
		stringstream s_stream(studentData[i]);
		while (s_stream.good()) {
			string substr;
			getline(s_stream, substr, ',');
			result.push_back(substr);
		}

		string studentID = result.at(0);
		string firstName = result.at(1);
		string lastName = result.at(2);
		string emailAddress = result.at(3);
		auto age = stoi(result.at(4));
		auto day1 = stoi(result.at(5));
		auto day2 = stoi(result.at(6));
		auto day3 = stoi(result.at(7));
		string degree = result.at(8);
		int daysToComplete[] = { day1, day2, day3 };
		//Student student = Student::Student(studentID, firstName, lastName, emailAddress, age, daysToComplete, degree);
		cout << endl << endl;
		roster.add(studentID, firstName, lastName, emailAddress, age, daysToComplete, degree);
	}


	// Test results

	cout << " ******** Print students on the roster"  << endl;

	for (int i = 0; i < roster.roster; i++) {
		Student student = *roster.classRosterArray[i];
		cout << student.getFirstName() << " " << student.getLastName() << endl;
	};


	/// <summary>
	/// Print of out the all students"
	/// </summary>
	/// <returns></returns>
	cout << endl << endl << endl;
	roster.printAll();
	roster.printInvalidEmails();
	roster.printAverageDaysInCourse("A5");
	roster.remove("A3");
	roster.printAll();

	return 0;
}



//GET DEGREE INFOR
int getDegree(string degree) {
		if (degree == "SOFTWARE") {
			return Degree::SOFTWARE;
		}
		else if (degree == "NETWORK") {
			return Degree::NETWORK;
		}
		else {
			return Degree::SECURITY;
		}
	};



/*

string getStudent(string student); // Fetches student from student array.
void split(string my_str, char delim); // Parses student array, converts student properties to strings
int getDegree(string degree); // fetches return value of degrees in enum
string greetings(string greet); // test function


int main() {

	// Declare variable holding studentData
	string studentData[5] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Dieudonne,Ntongwe,test@email.com,43,20,25,33,SOFTWARE"
	};

	cout << "Parse comma-delimited student data";
	string dieudonne = studentData[4];
	split(dieudonne, ',');

	//Test Functionality of Student Class
	//Days to complete program
	int dtc[3] = { 34, 3, 4 };
	//
	//std::cout << "Test student to test functionaltity" << endl;
	//Student student = Student::Student("D6", "Dieudonne", "Mesape", "dmn55@cornell.edu", 43, dtc, Degree::SOFTWARE );
	//student.setFirstName("Ntongwe");
	//cout << "StudentID: " << student.getStudentID() << endl;
	//cout << "Firstname: " << student.getFirstName() << endl;
	//cout << "Lastname: " << student.getLastName() << endl;
	//cout << "Email Address: " << student.getEmailAddress() << endl;
	//cout << "Age: " << student.getAge() << endl;
	//cout << "DaysToComplete " << student.getDaysToCompleteCourse() << endl;
	//cout << "Degree Program: " << student.getDegreeProgram() << endl;
	
	std::cout << "Test student to test functionaltity" << endl;
	Student student;
	student = Student::Student("D6", "Dieudonne", "Mesape", "dmn55@cornell.edu", 43, dtc, Degree::SOFTWARE);
	student.print();
	
	//Test Functionality of Roster

	classRoster roster;
	cout << "array without asterisk" << endl;
	cout << roster.classRosterArray << endl << endl;
	cout << "array 1 with asterisk" << endl;
	cout << *roster.classRosterArray << endl << endl;
	roster.add(student);
	
	cout << "array obtects" << endl;
	cout << roster.classRosterArray[0]->getAge() << endl << endl;

	






	// Enums
	std::cout << "Enum for SOFTWARE: " << Degree::SOFTWARE << endl;
	Degree software = Degree::SOFTWARE;
	std::cout <<"software:  " << software << endl;
	
	//convert from enum to string
	Degree b = static_cast<Degree>(1);
	std::cout << "convert from enum to string:  " << b << endl;
	
	std::cout << " " << endl;
	std::cout << "Content of split function...." << endl;
	split(studentData[4], ',');
	return  0;
}

string greetings(string greet) {
	std::cout << greet;
	return greet;
}


//Declare function to fetch students
string getStudent(string student) {
	return "Hello";
};

//GET DEGREE INFOR
int getDegree(string degree) {
	if (degree == "SOFTWARE") {
		return Degree::SOFTWARE;
	}
	else if (degree == "NETWORK") {
		return Degree::NETWORK;
	}
	else  {
		return Degree::SECURITY;
	}
};

//parse student string into a vector
void split(string my_str, char delim){
	vector<string> result; 
	stringstream s_stream(my_str); 
	while (s_stream.good()) {
		string substr;
		getline(s_stream, substr, delim);
		result.push_back(substr);
	}
	string studentID = result.at(0);
	string firstName = result.at(1);
	string lastName = result.at(2);
	string emailAddress = result.at(3);
	auto age = result.at(4);
	auto day1 = result.at(5);
	auto day2 = result.at(6);
	auto day3 = result.at(7);
	string degree = result.at(8);


	cout << "Output of split parser. " << endl;
	cout << "firstname: " << firstName << " lastname: " << lastName << " email address: " << emailAddress  << endl;
	cout << " age: " << age << " day1: " << day1 << " Degree: " << result.at(8) << endl;
	//classRoster::add(studentID, firstName, lastName, emailAddress, age, day1, day2, day3, getDegree(degree));
}



*/