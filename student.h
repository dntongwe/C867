#ifndef Student_class
#define Student_class

#include <iostream>
#include <string>
#include "degree.h"
using namespace std;

class Student
{
public:
	// create getter methods
	string getStudentID();
    string getFirstName();
	string getLastName();
	int getAge();
	string getEmailAddress();
    int getDaysToCompleteCourse(int i);
	int getDegreeProgram();

	//create setter methods
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setAge(int age);
	void setEmailAddress(string  emailAddress);
	void setDaysToCompleteCourse(int daysToCompleteCourse[]);
	void setDegreeProgram(string degreeProgram);


	//create constructors and destructor
	Student(string studentID, string firstname, string lastname, string emailAddress, int age, int daysToCompleteCourse[], string degreeProgram);
	~Student();
	virtual void print();

private:
	string studentID;
	string firstname;
	string lastname;
    int age;
	string emailAddress;
	int * daysToCompleteCourse;
	// degreeProgram;
	int degreeProgram;
};


#endif
