#include <iostream>
#include <string>
#include <vector>
#include<sstream>
#include "student.h"
#include "degree.h"
#include "roster.h"
using namespace std;


int main() {

	cout << " BEGIN ********* *Print Course title and Student ID **********************" << endl;
	cout << " ********* Course Title: Scripting and Programming Applications" << endl;
	cout << " ********* Student ID: #002751555      " << endl;
	cout << " ************************************************************************ END " 
	<< endl << endl;


	// Declare variable holding studentData
	string studentData[] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"#002751555,Dieudonne,Ntongwe,dntongwe@wgu.edu,43,20,25,33,SOFTWARE"
	};

	classRoster classRoster;

	for (int i = 0; i < 5; i++) {
		//parse data
		vector<string> result;
		stringstream s_stream(studentData[i]);
		while (s_stream.good()) {
			string substr;
			getline(s_stream, substr, ',');
			result.push_back(substr);
		}

		// Add parsed data to the roster
		string studentID = result.at(0);
		string firstName = result.at(1);
		string lastName = result.at(2);
		string emailAddress = result.at(3);
		string degree = result.at(8);
		auto age = stoi(result.at(4));
		auto day1 = stoi(result.at(5));
		auto day2 = stoi(result.at(6));
		auto day3 = stoi(result.at(7));
		int daysToComplete[3] = { day1, day2, day3 };
		classRoster.add(studentID, firstName, lastName, emailAddress, age, daysToComplete, degree);
	}

	classRoster.printAll();
	classRoster.printInvalidEmails();
	classRoster.printByDegreeProgram("SOFTWARE");
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.printInvalidEmails();
	classRoster.printAverageDaysInCourse("A1");

	return 0;
}

