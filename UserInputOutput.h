#pragma once
#include "Person.h"

class UserInputOutput{
    public:
    Person* setFullName();
    Person* setContactDetails(Person*);
    Person* editContactDetails(Person*);
    int selectFieldToEdit();
    string inputAddress();
    string inputCity();
    string inputState();
    int inputZipcode();
    long long inputPhoneNumber();
    int selectFieldToSort();
    int selectFieldToView();
};