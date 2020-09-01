#pragma once
#include <string>

using namespace std;

class Person
{
private:
    string first_name;
    string last_name;
    string address;
    string city;
    string state;
    int zip_code;
    long long phone_number;

public:
    Person(string first_name, string last_name);
    string getFullName();
    string getAddress();
    string getCity();
    string getState();
    int getZipcode();
    void setAddress(string);
    void setCity(string);
    void setState(string);
    void setZipcode(int);
    void setPhoneNumber(long long);
    long long getPhoneNumber();
    void display();
};