#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <array>
#include <utility>

class Phonebook {
public:
    Phonebook();

    const static int kNumContacts = 8;

    void show() const;
    void show(int index) const;
    bool add(Contact contact);

private:
    int numContacts;
    std::array<Contact, kNumContacts> contacts;

    std::string truncate(std::string &field, std::string::size_type width) const;
};

#endif
