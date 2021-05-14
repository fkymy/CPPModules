#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include "Phonebook.hpp"

Phonebook::Phonebook() {
    numContacts = 0;
}

std::string Phonebook::truncate(const std::string &field, std::string::size_type width) const {
    std::string ret;

    if (field.length() > width)
        ret = field.substr(0, width - 1) + ".";
    else
        ret = field;
    return ret;
}

void Phonebook::show() const {
    std::string firstName, lastName, nickname;

    for (int col = 0; col < 4; ++col)
        std::cout << std::setfill('-') << std::setw(10) << "" << "+";
    std::cout << std::setfill(' ') << std::endl;

    for (int row = 0; row < numContacts; ++row) {
        firstName = contacts[row].getFirstName();
        lastName = contacts[row].getLastName();
        nickname = contacts[row].getNickname();

        std::cout << std::right << std::setw(10) << row << "|";
        std::cout << std::right << std::setw(10) << truncate(firstName, 10) << "|";
        std::cout << std::right << std::setw(10) << truncate(lastName, 10) << "|";
        std::cout << std::right << std::setw(10) << truncate(nickname, 10) << "|";
        std::cout << std::endl;
    }

}

void Phonebook::show(int index) const {
    if (index < 0 || index > numContacts - 1) {
        std::cout << "Contact not found. " << std::endl;
        return;
    }
    contacts[index].displayInfo();
}

bool Phonebook::add(Contact contact) {
    if (numContacts == kNumContacts) return false;
    contacts[numContacts] = contact;
    ++numContacts;
    return true;
}
