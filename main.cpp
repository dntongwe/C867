#include <iostream>
#include <string>
#include <vector>
#include<sstream>
#include "student.h"
#include "degree.h"
#include "roster.h"
using namespace std;



//Declare course title and provide student ID
int main() {
	cout << endl;
	cout << " ***********************************************************************" << endl;
	cout << " ********* Course Title: Scripting and Programming Applications - C867" << endl;
	cout << " ********* Student ID: #002751555      " << endl;
	cout << " ***********************************************************************" << endl;
	cout << endl;

	// Declare array and pass to it studentData
	string studentData[] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"#002751555,Dieudonne,Ntongwe,dntongwe@wgu.edu,43,20,25,33,SOFTWARE"
	};

	Roster classRoster; //instantiate a roster object

	//loop through string array to parse student data and instantiate student objects
	for (int i = 0; i < 5; i++) {
		//parse data
		vector<string> student;
		stringstream s_stream(studentData[i]);
		while (s_stream.good()) {
			string substr;
			getline(s_stream, substr, ',');
			student.push_back(substr);
		}
		// instantiate student based parsed data to the roster
		string studentID = student.at(0);
		string firstName = student.at(1);
		string lastName = student.at(2);
		string emailAddress = student.at(3);
		string degree = student.at(8);
		auto age = stoi(student.at(4));
		auto daysInCourse1 = stoi(student.at(5));
		auto daysInCourse2 = stoi(student.at(6));
		auto daysInCourse3 = stoi(student.at(7));
		classRoster.add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
	}

	//test properties and methods of roster object
	classRoster.printAll(); //prints students on roster
	classRoster.printInvalidEmails(); //lists students with invalid email addresses
	classRoster.printAverageDaysInCourse("#002751555"); //calculates and prints average time per course
	classRoster.printByDegreeProgram(SOFTWARE);// lists students in a given program
	classRoster.printAll();
	classRoster.remove("A3"); //removes given students from roster
	classRoster.printAll(); 
	classRoster.remove("A3");
	classRoster.printAll();


	cout << endl << endl;
	cout << "End of submission!!. Much appreciated." << endl << endl << endl;


	system("PAUSE");
	return 0;
}


