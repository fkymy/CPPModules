#include <array>
#include <cctype>
#include <sstream>
#include <iostream>
#include <string>

#include "Phonebook.hpp"
#include "Contact.hpp"

bool validCommand(const std::string &s) {
    return s == "EXIT" || s == "ADD" || s == "SEARCH";
}

std::string getCommand(const std::string& prompt = "Enter a command: ",
                  const std::string& reprompt = "Not a command. Try again\n") {
    while (true) {
        std::cout << prompt;
        std::string line;
        if (!std::getline(std::cin, line))
            return "EXIT";

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
        std::getline(std::cin, line);

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

#define X(field, prompt)     \
    std::cout << prompt << ": ";  \
    std::getline(std::cin, line); \
    newContact.set(#field, line);
    CONTACT_FIELDS
#undef X

    if (!phonebook.add(newContact)) {
        std::cout << "Failed to add phonebook." << std::endl;
    } else {
        std::cout << "Contact added." << std::endl;
    }
}

void searchContact(Phonebook& phonebook) {
    int index;

    phonebook.show();
    index = getInteger("index: ");
    phonebook.show(index);
}

// #include <vector>
// std::string test() {
//     std::vector<string> v(10);
//
//     v[0] = "hello";
//
//     return v[0];
// }

int main() {
    // Contact contact;
    //
    // contact.set("firstName", "yufukuya");
    //
    // // std::cout << contact.getFirstName() << std::endl;
    //
    // // std::cout << (contact.getFirstName() = "fkymy") << std::endl;
    // // std::cout << (contact.getFirstName() += "why") << std::endl;
    //
    // std::string firstName = contact.getFirstName();
    //
    // std::cout << firstName << std::endl;
    // firstName = "fkymy";
    // std::cout << firstName << std::endl;
    //
    // std::cout << contact.getFirstName() << std::endl;


    Phonebook phonebook;
    std::string command;

    while (true) {
        command = getCommand("phonebook> ");
        if (command == "EXIT")
            return 0;
        if (command == "ADD")
            addContact(phonebook);
        if (command == "SEARCH")
            searchContact(phonebook);
    }
    return 0;
}
