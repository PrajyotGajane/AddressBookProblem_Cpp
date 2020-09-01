#include <iostream>
#include "Person.h"
#include "UserInputOutput.h"

using namespace std;

Person *addContact()
{
    UserInputOutput input;
    Person *person = input.setFullName();
    input.setContactDetails(person);
    return person;
}

void display(Person *person)
{
    if(person != nullptr)
        person->display();
    else
        cout << "After delete" << endl;
}

void editContactDetails(Person *person)
{
    UserInputOutput editInput;
    cout << "Edit contact information" << endl;
    editInput.setContactDetails(person);
}

void displayWelcomeMessage()
{
    cout << "Welcomem to Address Book Problem" << endl;
}

void deleteContact(Person *person)
{
    delete person;
    cout << "Contact Deleted" << endl;
}

int main()
{
    displayWelcomeMessage();
    Person *person = addContact();
    display(person);
    editContactDetails(person);
    display(person);
    deleteContact(person);
    return 0;
}