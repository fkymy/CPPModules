#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <array>
#include <utility>

class Phonebook {
public:
    Phonebook();

    void show() const;
    void show(int index) const;
    bool add(Contact contact);

private:
    const static int kNumContacts = 8;
    int numContacts;
    Contact contacts[kNumContacts];
    // std::array<Contact, kNumContacts> contacts;

    std::string truncate(const std::string &field, std::string::size_type width) const;
};

#endif
