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


int Student::getDaysToCompleteCourse(int i)
{

     return  this->daysToCompleteCourse[i];

 }
 

string Student::getDegreeProgram () {
    
    if (degreeProgram == Degree::SOFTWARE) {
        return "Software";
    }
    else if (degreeProgram == Degree::NETWORK) {
        return "Network";
    }
    else if (degreeProgram == Degree::SECURITY) {
        return "Security";
    }
    else {
        return "Not Entered";
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



void Student::setDaysToCompleteCourse(int daysToCompleteCourse[3])
{
    for (int i = 0; i < 3; i++) {
        this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
     }
}

Student::Student(string studentID, string firstname, string lastname, string emailAddress, int age, int daysToCompleteCourse[3], string degreeProgram) {
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
   // cout << "StudentID: " << getStudentID() << '\t';
    cout << "First Name: " << Student::getFirstName() << '\t';
    cout << "Last Name: " << Student::getLastName() << '\t';
    cout << "Age: " << Student::getAge() <<  '\t';
    cout << "Contact email: " << Student::getEmailAddress() << '\t';
    
    cout << "daysInCourse: " <<"{"<< this->daysToCompleteCourse[0] << ", " << this->daysToCompleteCourse[1] << ", " << this->daysToCompleteCourse[2] <<"}"<<'\t';

    //cout << "daysInCourse: " <<"{"<< this->getDaysToCompleteCourse(0)<< ", " << this->getDaysToCompleteCourse(1) << ", " << this->getDaysToCompleteCourse(2) <<"}"<<'\t';
    cout << "Degree Program: " << Student::getDegreeProgram() << '\t';
    cout << endl;
};
