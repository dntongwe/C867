#ifndef Roster_class
#define Roster_class

#include <iostream>
#include "degree.h"
#include "student.h"
using namespace std;


class Roster
{
	public:
		Roster();
		~Roster();
		Student* classRosterArray[5];
		void add(string studentID, string firstname, string lastname, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string degreeProgram);
		void remove(string studentID);
		void printAll();
		void printAverageDaysInCourse(string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(Degree degreeProgram);
		//void printByDegreeProgram(string degreeProgram); // function overlop, search by string also
		void setclassRosterArray();
		int roster;	

    private:
};

#endif
