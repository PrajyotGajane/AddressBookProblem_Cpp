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
        cout << "\n1: Add Contact 2: Edit Contact 3: Display 4: Delete 5: Sort 7: View 8: Search 9: End" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            Person *personPtr;
            personPtr = userInputOutput.setFullName();
            if (addressBook.duplicateContact(personPtr))
            {
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
            int sortChoice;
            sortChoice = userInputOutput.selectFieldToSort();
            addressBook.sort(sortChoice);
            break;
        case 7:
            {
                int viewChoice;
                viewChoice = userInputOutput.selectFieldToView();
                switch (viewChoice)
                {
                case 1:
                    addressBook.viewByCity(userInputOutput.inputCity());
                    break;
                case 2:
                    addressBook.viewByState(userInputOutput.inputState());
                    break;
                default:
                    break;
                }
            }
            break;
        case 8:
            {
            string search_city_state;
            search_city_state = userInputOutput.inputCityOrState();
            addressBook.searchCityState(search_city_state);
            }
            break;
        case 9:
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