#include <iostream>
#include "student.h"
#include "degree.h"
using namespace std;




void Student::getK() {

    //for (int i = 0; i < 3; i++) {
        //cout << "Array element " << i << " = ";
        //cout << *(daysToCompleteCourse + i) << endl << endl;
       // cout << "{" << *(daysToCompleteCourse + i) << " " << *(daysToCompleteCourse + 1) << " " << *(daysToCompleteCourse + 2) << "}" << endl << endl;

   // };

    cout << "{" << *(daysToCompleteCourse ) << " " << *(daysToCompleteCourse + 1) << " " << *(daysToCompleteCourse + 2) << "}" << endl << endl;
}
   
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

string Student::getDegreeProgram () {
    
    if (degreeProgram == Degree::SOFTWARE) {
        return "SOFTWARE";
    }
    else if (degreeProgram == Degree::NETWORK) {
        return "NETWORK";
    }
    else if (degreeProgram == Degree::SECURITY) {
        return "SECURITY";
    }
    else {
        return "UNKNOWN";
    }
}

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
        else if (degreeProgram == "SECURITY") {
            this->degreeProgram = Degree::SECURITY;
        } 
        else {
            this->degreeProgram = Degree::UNKNOWN;
        }
}

void Student::setDegreeProgram(Degree degreeProgram) {
    this->degreeProgram = degreeProgram;
};

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
    getK();
}

//destructor
Student::~Student() {};


void Student::print() {
    cout << "StudentID: " << getStudentID() << '\t';
    cout << "First Name: " << getFirstName() << '\t';
    cout << "Last Name: " << getLastName() << '\t';
    cout << "Age: " << getAge() <<  '\t';
    cout << "Contact email: " << getEmailAddress() << '\t';
    //cout << Student::getK() << '\t';
    cout << "Days To Complete Program :" << " { " << Student::getDaysToCompleteCourse() <<" " << Student::getDaysToCompleteCourse(1) << " " << Student::getDaysToCompleteCourse(2) <<  " }" <<'\t' <<endl;
    cout << "Degree Program: " <<getDegreeProgram() << '\t';
    cout << endl;
};
