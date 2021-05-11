#include <array>
#include <cctype>
#include <sstream>
#include <iostream>
#include <string>

#include "Phonebook.hpp"
#include "Contact.hpp"

using std::cout;     using std::cin;
using std::endl;     using std::string;

bool validCommand(const string &s) {
    return s == "EXIT" || s == "ADD" || s == "SEARCH";
}

string getCommand(const string& prompt = "Enter a command: ",
                  const string& reprompt = "Not a command. Try again\n") {
    while (true) {
        cout << prompt;
        string line;
        if (!std::getline(cin, line))
            return "EXIT";

        if (line.empty())
            continue;

        if (validCommand(line))
            return line;

        cout << reprompt << endl;
    }
}

int getInteger(const string& prompt = "Enter an integer: ",
               const string& reprompt = "Illegal numeric format. Try again\n") {
    while (true) {
        cout << prompt;
        string line;
        std::getline(cin, line);

        std::istringstream iss(line);
        int value; char remain;
        if (iss >> value && !(iss >> remain))
            return value;

        cout << reprompt << endl;
    }
}

void addContact(Phonebook& phonebook) {
    Contact newContact;
    string line;

#define X(field, prompt)          \
    cout << prompt << ": ";       \
    std::getline(cin, line);      \
    newContact.set(#field, line);
    CONTACT_FIELDS
#undef X

    if (!phonebook.add(newContact)) {
        cout << "Failed to add phonebook." << endl;
    } else {
        cout << "Contact added." << endl;
    }
}

void searchContact(Phonebook& phonebook) {
    int index;

    phonebook.show();
    index = getInteger("index: ");
    phonebook.show(index);
}

int main() {
    Phonebook phonebook;
    string command;

    while (true) {
        command = getCommand("phonebook> ");
        if (command == "EXIT") {
            cout << "Quitting..." << endl;
            return 0;
        }
        if (command == "ADD")
            addContact(phonebook);
        if (command == "SEARCH")
            searchContact(phonebook);
    }

    return 0;
}
