#include <iostream>
#include <string>
#include <utility>
#include "Phonebook.hpp"

Phonebook::Phonebook() {
    numContacts = 0;
}

void Phonebook::show() const {
    // index, firstname, lastname, nickname
    std::cout << "listing all contacts:" << std::endl;
    for (int i = 0; i < numContacts; ++i) {
        std::cout << i << " " << contacts[i].getFirstName() << std::endl;
    }
}

bool Phonebook::add(Contact contact) {
    if (numContacts == kNumContacts) return false;
    contacts[numContacts] = contact;
    ++numContacts;
    return true;
}

std::pair<Contact, bool> Phonebook::get(int index) const {
    if (index < 0 || index > numContacts - 1)
        return std::make_pair(Contact(), false);
    return std::make_pair(contacts[index], true);
}
