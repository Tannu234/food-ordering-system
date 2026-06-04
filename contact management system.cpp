#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact {
public:
    string name;
    string phone;
    string email;

    Contact(string n, string p, string e) {
        name = n;
        phone = p;
        email = e;
    }
};

vector<Contact> contacts;

// Add Contact
void addContact() {
    string name, phone, email;

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Phone Number: ";
    getline(cin, phone);

    cout << "Enter Email: ";
    getline(cin, email);

    contacts.push_back(Contact(name, phone, email));
    cout << "\nContact Added Successfully!\n";
}

// Display All Contacts
void displayContacts() {
    if (contacts.empty()) {
        cout << "\nNo contacts available.\n";
        return;
    }

    cout << "\n--- Contact List ---\n";
    for (int i = 0; i < contacts.size(); i++) {
        cout << "\nContact " << i + 1 << endl;
        cout << "Name  : " << contacts[i].name << endl;
        cout << "Phone : " << contacts[i].phone << endl;
        cout << "Email : " << contacts[i].email << endl;
    }
}

// Search Contact
void searchContact() {
    string searchName;

    cin.ignore();
    cout << "Enter name to search: ";
    getline(cin, searchName);

    bool found = false;

    for (auto &contact : contacts) {
        if (contact.name == searchName) {
            cout << "\nContact Found:\n";
            cout << "Name  : " << contact.name << endl;
            cout << "Phone : " << contact.phone << endl;
            cout << "Email : " << contact.email << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nContact not found.\n";
}

// Delete Contact
void deleteContact() {
    string deleteName;

    cin.ignore();
    cout << "Enter name to delete: ";
    getline(cin, deleteName);

    for (auto it = contacts.begin(); it != contacts.end(); it++) {
        if (it->name == deleteName) {
            contacts.erase(it);
            cout << "\nContact Deleted Successfully!\n";
            return;
        }
    }

    cout << "\nContact not found.\n";
}

// Update Contact
void updateContact() {
    string updateName;

    cin.ignore();
    cout << "Enter name to update: ";
    getline(cin, updateName);

    for (auto &contact : contacts) {
        if (contact.name == updateName) {
            cout << "Enter New Phone Number: ";
            getline(cin, contact.phone);

            cout << "Enter New Email: ";
            getline(cin, contact.email);

            cout << "\nContact Updated Successfully!\n";
            return;
        }
    }

    cout << "\nContact not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== Contact Management System =====\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Update Contact\n";
        cout << "5. Delete Contact\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                updateContact();
                break;
            case 5:
                deleteContact();
                break;
            case 6:
                cout << "Exiting Program...\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}