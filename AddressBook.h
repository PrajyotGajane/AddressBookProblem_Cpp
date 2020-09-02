#pragma once
#include "Person.h"

class AddressBook{
    public:
    void addContact(Person*);
    int deleteContact(Person*);
    void display();
    void editContactDetails(Person*);
};