#include "Student.h"
#include <iostream>

using namespace std;

Student::Student()
{
    cout << "First name: ";
    cin >> firstName;
    cout << endl << "Last name: ";
    cin >> lastName;
    cout << endl << "ID number: ";
    cin >> idNumber;
}

void Student::printStudent()
{
    cout << "ID# " << idNumber << " - " << firstName << ", " << lastName;
}
