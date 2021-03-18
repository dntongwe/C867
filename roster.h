#ifndef Roster_class
#define Roster_class

#include <iostream>
#include "student.h"
#include "degree.h"
using namespace std;


class classRoster
{
	public:
		classRoster();
		Student* classRosterArray[5];
		int rosterSize = 0;
		void add(string studentID, string firstname, string lastname, string emailAddress, int age, int daysToCompleteCourse[], string degreeProgram);
		void remove(string studentID);
		void printAll();
		void printAverageDaysInCourse(string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(string degreeProgram);
		void setclassRosterArray();
		int roster;

    private:
		
        


};

#endif
