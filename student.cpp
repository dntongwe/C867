#include <iostream>
#include "student.h"
#include "degree.h"
using namespace std;



/*
** Setters
*/

string Student::getStudentID()
{
    return studentID;
}


string Student::getFirstName()
{
   return firstname;
}


string Student::getLastName()
{
    return lastname;
}

int Student::getAge()
{
    return age;
}


string Student::getEmailAddress()
{
    return emailAddress;
}


int Student::getDaysToCompleteCourse(int i = 0)
{
    return *(daysToCompleteCourse + i);
}

int getDegreeProgram() {
    //return degreeProgram;
    return 0;
};

/// <summary>
///  setters
/// </summary>
///  

void Student::setStudentID(string studentID)
{
    this->studentID = studentID;
}

void Student::setFirstName(string firstName)
{
    this->firstname = firstName;
}

void Student::setLastName(string lastName)
{
    this->lastname = lastName;
}


void Student::setAge(int age)
{
    this->age = age;
}

void Student::setEmailAddress(string emailAddress)
{
    this->emailAddress = emailAddress;
}

void Student::setDegreeProgram(string degreeProgram)
{
        if (degreeProgram == "SOFTWARE") {
            this->degreeProgram = Degree::SOFTWARE;
        }
        else if (degreeProgram == "NETWORK") {
            this->degreeProgram = Degree::NETWORK;
        }
        else {
            this->degreeProgram = Degree::SECURITY;
        }
}


void Student::setDaysToCompleteCourse(int daysToCompleteCourse[])
{
        this->daysToCompleteCourse = daysToCompleteCourse;
}

Student::Student(string studentID, string firstname, string lastname, string emailAddress, int age, int daysToCompleteCourse[], string degreeProgram) {
    setStudentID(studentID);
    setFirstName(firstname);
    setLastName(lastname);
    setAge(age);
    setEmailAddress(emailAddress);
    setDegreeProgram(degreeProgram);
    setDaysToCompleteCourse(daysToCompleteCourse);
}

//destructor
Student::~Student() {};




void Student::print() {
    cout << "StudentID: " << getStudentID() << '\t';
    cout << "First Name: " << getFirstName() << '\t';
    cout << "Last Name: " << getLastName() << '\t';
    cout << "Age: " << getAge() <<  '\t';
    cout << "Contact email: " << getEmailAddress() << '\t';
    cout << "Days To Complete Program :" << "{" << getDaysToCompleteCourse() <<" " << getDaysToCompleteCourse(1) << " " << getDaysToCompleteCourse(2) << "}" <<'\t';
    //cout << "Degree Program: " <<getDegreeProgram() << '\t';
    cout << endl << endl << endl;
};
