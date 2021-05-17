#include <array>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

#include "Contact.hpp"
#include "Phonebook.hpp"

bool validCommand(const std::string &s) {
    return s == "EXIT" || s == "ADD" || s == "SEARCH";
}

std::string getCommand(const std::string& prompt = "Enter a command: ",
                  const std::string& reprompt = "Not a command. Try again.\n") {
    while (true) {
        std::cout << prompt;

        std::string line;
        if (!std::getline(std::cin, line))
            std::exit(0);

        if (line.empty())
            continue;

        if (validCommand(line))
            return line;

        std::cout << reprompt << std::endl;
    }
}

int getInteger(const std::string& prompt = "Enter an integer: ",
               const std::string& reprompt = "Illegal numeric format. Try again\n") {
    while (true) {
        std::cout << prompt;

        std::string line;
        if (!std::getline(std::cin, line))
            std::exit(0);

        std::istringstream iss(line);
        int value; char remain;
        if (iss >> value && !(iss >> remain))
            return value;

        std::cout << reprompt << std::endl;
    }
}

void addContact(Phonebook& phonebook) {
    Contact newContact;
    std::string line;

#define X(field, prompt)                             \
    std::cout << prompt << ": ";                     \
    if (!std::getline(std::cin, line)) std::exit(0); \
    newContact.set(#field, line);
    CONTACT_FIELDS
#undef X

    if (!phonebook.add(newContact))
        std::cout << "Failed to add contact." << std::endl;
    else
        std::cout << "Contact added." << std::endl;
}

void searchContact(Phonebook& phonebook) {
    int index;

    phonebook.show();
    if (phonebook.getNumContacts() == 0)
        return;
    index = getInteger("index: ");
    phonebook.show(index);
}

int main() {
    Phonebook phonebook;
    std::string command;

    while (true) {
        command = getCommand("phonebook> ");
        if (command == "EXIT")
            std::exit(0);
        if (command == "ADD")
            addContact(phonebook);
        if (command == "SEARCH")
            searchContact(phonebook);
    }
    return 0;
}
