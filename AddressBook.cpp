#include "AddressBook.h"
#include "Person.h"
#include "UserInputOutput.h"
#include <list>
#include <iostream>

using namespace std;

list<Person *> contact_list;

UserInputOutput userInput;

void AddressBook::addContact(Person *person)
{
    contact_list.push_back(person);
}

Person *findContactPointer(Person *person)
{
    bool foundFlag = false;
    for (auto contact_pointers = contact_list.begin(); contact_pointers != contact_list.end(); ++contact_pointers)
    {
        string checkName = (*contact_pointers)->getFullName();
        if (checkName == person->getFullName())
        {
            foundFlag = true;
            return *contact_pointers;
        }
    }
    return nullptr;
}

bool AddressBook::duplicateContact(Person *person)
{
    bool duplicateExist = false;
    if (findContactPointer(person) != nullptr)
        duplicateExist = true;
    return duplicateExist;
}

void AddressBook::editContactDetails(Person *person)
{
    Person *editPerson = findContactPointer(person);
    bool flag = true;
    if (editPerson != nullptr)
    {
        do
        {
            int selectField = userInput.selectFieldToEdit();
            switch (selectField)
            {
            case 1:
                editPerson->setAddress(userInput.inputAddress());
                break;
            case 2:
                editPerson->setCity(userInput.inputCity());
                break;
            case 3:
                editPerson->setState(userInput.inputState());
                break;
            case 4:
                person->setZipcode(userInput.inputZipcode());
                break;
            case 5:
                editPerson->setPhoneNumber(userInput.inputPhoneNumber());
                break;
            case 6:
                flag = false;
                break;
            default:
                cout << "\nPlease Select valid Input." << endl;
                break;
            }
        } while (flag);
    }
    else
    {
        cout << "Contact doesn't exist" << endl;
    }
}

int AddressBook::deleteContact(Person *person)
{
    int count;
    Person *personDelete = findContactPointer(person);
    if (personDelete != nullptr)
    {
        contact_list.remove(personDelete);
        count = 1;
    }
    else
    {
        count = 0;
    }
    return count;
}

void AddressBook::display()
{
    if (contact_list.empty())
        cout << "\nNo data" << endl;
    for (auto contact_pointers = contact_list.begin(); contact_pointers != contact_list.end(); ++contact_pointers)
    {
        (*contact_pointers)->display();
    }
}

void AddressBook::sortByName()
{
    contact_list.sort([](Person *firstPerson, Person *secondPerson) { return firstPerson->getFullName() < secondPerson->getFullName(); });
    display();
}