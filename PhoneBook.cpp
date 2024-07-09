#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

// Define a structure for Contact.
struct Contact
{
    string name;
    string surName;
    string phoneNumber;
};

// Function declarations
void AddContact(vector<Contact>& contacts);
void saveContacts(vector<Contact>& contacts, string& fileName);
void loadContacts(vector<Contact>& contacts, string& fileName, Contact& person);
void SearchContact(vector<Contact>& contacts);
void UpdateContact(vector<Contact>& contacts, string& fileName);
void DeleteContact(vector<Contact>& contacts, string& fileName);
void ListContact(vector<Contact>& contacts);
void resetConsoleColor();

int main()
{
    Contact person;
    vector<Contact> contacts;
    string fileName = "contacts.txt";
    loadContacts(contacts, fileName, person); // Load contacts from file.
    int choice;
    while (true)
    {
        system("cls");
        resetConsoleColor();
        cout << "Welcome to the phone book application!\n\n" << endl;
        cout << "Please make your selection: " << endl << endl;
        cout << "1. Add contact " << endl;
        cout << "2. Search contact " << endl;
        cout << "3. Update Contact " << endl;
        cout << "4. Delete Contact " << endl;
        cout << "5. List Contacts " << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            AddContact(contacts);
            saveContacts(contacts, fileName);
            break;
        case 2:
            SearchContact(contacts);
            break;
        case 3:
            UpdateContact(contacts, fileName);
            break;
        case 4:
            DeleteContact(contacts, fileName);
            break;
        case 5:
            ListContact(contacts);
            break;
        case 6:
            system("color 0C");
            cout << endl;
            cout << "Exiting...\n ";
            return 0;
        default:
            system("color 0C");
            cout << endl << "Invalid choice. Exiting.\n " << endl;
            return 0;
        }
    }
    cout << endl;
    return 0;
}

// Reset console color to default.
void resetConsoleColor()
{
    system("color 07");
}

// Function to add a new contact.
void AddContact(vector<Contact>& contacts)
{
    system("cls");
    int chocie;
    cout << "Enter 1 to add contact or -1 to exit: ";
    cin >> chocie;
    cout << endl << endl;
    while (chocie == 1)
    {
        system("color 0A");
        Contact newContact;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, newContact.name);
        cout << "Enter surname: ";
        getline(cin, newContact.surName);
        cout << "Enter phone number: ";
        getline(cin, newContact.phoneNumber);
        contacts.push_back({ newContact.name, newContact.surName, newContact.phoneNumber });
        cout << "Contact added successfully." << endl;
        system("pause");
        break;
    }
}

// Function to save contacts to a file.
void saveContacts(vector<Contact>& contacts, string& fileName)
{
    ofstream outFile(fileName, ios::trunc);
    if (!outFile.is_open())
    {
        cout << "Unable to open file for writing! " << endl;
        return;
    }
    else
    {
        for (auto& contact : contacts)
        {
            outFile << contact.name << "," << contact.surName << "," << contact.phoneNumber << endl;
        }
        outFile.close();
    }
}

// Function to load contacts from a file.
void loadContacts(vector<Contact>& contacts, string& fileName, Contact& person)
{
    ifstream inFile(fileName, ios::in);
    if (!inFile.is_open())
    {
        cout << "Unable to open file for reading! " << endl;
    }
    else
    {
        contacts.clear();
        string line;
        while (getline(inFile, line))
        {
            istringstream iss(line);
            getline(iss, person.name, ',');
            getline(iss, person.surName, ',');
            getline(iss, person.phoneNumber, ',');
            contacts.push_back({ person.name, person.surName, person.phoneNumber });
        }
        inFile.close();
    }
}

// Function to search for a contact.
void SearchContact(vector<Contact>& contacts)
{
    system("cls");
    int chocie;
    cout << "Enter 1 to search contact or -1 to exit: ";
    cin >> chocie;
    cout << endl << endl;
    while (chocie == 1)
    {
        system("color 0B");
        Contact find;
        cout << "Enter name to search: ";
        cin.ignore();
        getline(cin, find.name);
        cout << "Enter surname to search: ";
        getline(cin, find.surName);

        bool found = false;

        for (auto it = contacts.begin(); it != contacts.end();)
        {
            if (it->name == find.name && it->surName == find.surName)
            {
                cout << "Contact found: " << endl << "Name: " << it->name << "\t" << "Surname: " << it->surName << "\t" << "PhoneNumber: " << it->phoneNumber << endl;
                found = true;
                system("pause");
                break;
            }
            else
            {
                ++it;
            }
        }
        if (!found)
        {
            cout << "Contact not found! " << endl;
            system("pause");
        }
        break;
    }
}

// Function to update a contact.
void UpdateContact(vector<Contact>& contacts, string& fileName)
{
    system("cls");
    int choice;
    cout << "Enter 1 to update contact or -1 to exit: ";
    cin >> choice;
    cout << endl << endl;
    while (choice == 1)
    {
        system("color 0E");
        Contact update;
        cout << "Enter name to update: ";
        cin.ignore();
        getline(cin, update.name);
        cout << "Enter surname to update: ";
        getline(cin, update.surName);

        bool found = false;

        for (auto it = contacts.begin(); it != contacts.end();)
        {
            if (it->name == update.name && it->surName == update.surName)
            {
                cout << "Contact found: " << endl << "Name: " << it->name << "\t" << "Surname: " << it->surName << "\t" << "PhoneNumber: " << it->phoneNumber << endl;
                cout << "Enter new name: ";
                getline(cin, it->name);
                cout << "Enter new surname: ";
                getline(cin, it->surName);
                cout << "Enter new phone number: ";
                getline(cin, it->phoneNumber);
                cout << "Contact updated successfully." << endl;
                found = true;
                saveContacts(contacts, fileName);
                system("pause");
                break;
            }
            else
            {
                ++it;
            }
        }
        if (!found)
        {
            cout << "Contact not found! " << endl;
            system("pause");
        }
        break;
    }
}

// Function to delete a contact.
void DeleteContact(vector<Contact>& contacts, string& fileName)
{
    system("cls");
    int choice;
    cout << "Enter 1 to delete contact or -1 to exit: ";
    cin >> choice;
    cout << endl << endl;
    while (choice == 1)
    {
        system("color 0C");
        Contact del;
        cout << "Enter name to delete: ";
        cin.ignore();
        getline(cin, del.name);
        cout << "Enter surname to delete: ";
        getline(cin, del.surName);

        bool found = false;

        for (auto it = contacts.begin(); it != contacts.end();)
        {
            if (it->name == del.name && it->surName == del.surName)
            {
                cout << "Contact found: " << endl << "Name: " << it->name << "\t" << "Surname: " << it->surName << "\t" << "PhoneNumber: " << it->phoneNumber << endl;
                it = contacts.erase(it);
                cout << "Contact deleted successfully. " << endl;
                found = true;
                saveContacts(contacts, fileName);
                system("pause");
                break;
            }
            else
            {
                ++it;
            }
        }
        if (!found)
        {
            cout << "Contact not found! " << endl;
            system("pause");
        }
        break;
    }
}

// Function to list all contacts.
void ListContact(vector<Contact>& contacts)
{
    system("cls");
    int chocie;
    cout << "Enter 1 to list contacts or -1 to exit: ";
    cin >> chocie;
    cout << endl << endl;
    while (chocie == 1)
    {
        system("color 0E");
        if (contacts.empty())
        {
            cout << "No contacts found! " << endl << endl;
            system("pause");
            break;
        }
        else
        {
            for (auto& contact : contacts)
            {
                // Print the contact details with each field left-aligned and set to a width of 30 characters.
                cout << "Name: " << setw(30) << left << contact.name
                    << "Surname: " << setw(30) << left << contact.surName
                    << "PhoneNumber: " << setw(30) << left << contact.phoneNumber << endl;
            }
            cout << endl;
            system("pause");
            break;
        }
    }
}
