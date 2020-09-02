#pragma once
#include "Person.h"

class AddressBook{
    public:
    void addContact(Person*);
    int deleteContact(Person*);
    void display();
    bool duplicateContact(Person*);
    void editContactDetails(Person*);
    void sort(int);
};