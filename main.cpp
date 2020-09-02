#include <iostream>
#include "Person.h"
#include "UserInputOutput.h"
#include "AddressBook.h"

using namespace std;

void performTask()
{
    bool endKey = true;
    while (endKey)
    {
        int choice;
        AddressBook addressBook;
        UserInputOutput userInputOutput;
        cout << "\n 1: Add Contact 2: Edit Contact 3: Display 4: Delete 5: Sort 6:End" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            Person *personPtr;
            personPtr = userInputOutput.setFullName();
            if (addressBook.duplicateContact(personPtr)){
                cout << "Contact already exists!!!!!" << endl;
                break;
            }
            userInputOutput.setContactDetails(personPtr);
            addressBook.addContact(personPtr);
            break;
        case 2:
            Person *personEdit;
            personEdit = userInputOutput.setFullName();
            addressBook.editContactDetails(personEdit);
            break;
        case 3:
            addressBook.display();
            break;
        case 4:
            Person *personDelete;
            personDelete = userInputOutput.setFullName();
            if (addressBook.deleteContact(personDelete) == 0)
            {
                cout << "\nNo Data Found\n";
            }
            else
            {
                cout << "\nDeleted Successfully\n";
            }
            delete personDelete;
            break;
        case 5:
            addressBook.sortByName();
            break;
        case 6:
            endKey = false;
            break;
        default:
            cout << "Invalid Input" << endl;
            break;
        }
    }
}

void displayWelcomeMessage()
{
    cout << "Welcomem to Address Book Problem" << endl;
}

int main()
{
    displayWelcomeMessage();
    performTask();
    return 0;
}