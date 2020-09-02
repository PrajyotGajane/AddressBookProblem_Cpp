#include <iostream>
#include "UserInputOutput.h"
#include "Person.h"

using namespace std;

Person *UserInputOutput::setFullName()
{
    string first_name;
    string last_name;
    cout << "\nEnter the First Name : ";
    cin >> first_name;
    cout << "\nEnter the Last Name : ";
    cin >> last_name;
    Person *person = new Person(first_name, last_name);
    return person;
}

Person *UserInputOutput::setContactDetails(Person *person)
{
    person->setAddress(inputAddress());
    person->setCity(inputCity());
    person->setState(inputState());
    person->setZipcode(inputZipcode());
    person->setPhoneNumber(inputPhoneNumber());
    return person;
}

string UserInputOutput::inputAddress()
{
    string address;
    cout << "\nEnter the Address : ";
    cin.ignore();
    getline(cin, address);
    return address;
}

string UserInputOutput::inputCity()
{
    string city;
    cout << "\nEnter the City : ";
    cin >> city;
    return city;
}

string UserInputOutput::inputState()
{
    string state;
    cout << "\nEnter the State : ";
    cin >> state;
    return state;
}

int UserInputOutput::inputZipcode()
{
    int zip_code;
    cout << "\nEnter the Zipcode : ";
    cin >> zip_code;
    return zip_code;
}

long long UserInputOutput::inputPhoneNumber()
{
    long long phone_number;
    cout << "\nEnter the phone number : ";
    cin >> phone_number;
    return phone_number;
}

int UserInputOutput::selectFieldToEdit()
{
    int choice;
    cout << "\nEdit:\n 1: Address  2: City  3: State  4:Zipcode  5:Phone Number  6: Exit : ";
    cin >> choice;
    return choice;
}

int UserInputOutput::selectFieldToSort()
{
    int choice;
    cout << "\nSort:\n1: By Name  2: By City  3: By State  4: By Zipcode : ";
    cin >> choice;
    return choice;
}