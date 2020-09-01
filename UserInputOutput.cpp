#include <iostream>
#include "UserInputOutput.h"
#include "Person.h"

using namespace std;

Person* UserInputOutput::setFullName(){
    string first_name;
    string last_name;
    cout <<"\nEnter the First Name : ";
    cin >> first_name;
    cout <<"\nEnter the Last Name : ";
    cin >> last_name;
    Person* person = new Person(first_name, last_name);
    return person;
}

Person* UserInputOutput::setContactDetails(Person * person){
    string address;
    string city;
    string state;
    int zip_code;
    long long phone_number;
    cout << "\nEnter the Address : ";
    cin.ignore();
    getline(cin, address);
    person->setAddress(address);
    cout << "\nEnter the City : ";
    cin >> city;
    person->setCity(city);
    cout << "\nEnter the State : ";
    cin >> state;
    person->setState(state);
    cout << "\nEnter the 6 Digit Zip code : ";
    cin >> zip_code;
    person->setZipcode(zip_code);
    cout <<"\nEnter the 10 Digit Mobile Number : ";
    cin >> phone_number;
    person->setPhoneNumber(phone_number);
    return person;
}