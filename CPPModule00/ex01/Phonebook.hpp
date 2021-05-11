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
    bool add(Contact contact);
    std::pair<Contact, bool> get(int index) const;


private:
    int numContacts;
    std::array<Contact, kNumContacts> contacts;

    bool validCommand();
    bool full() const;
};

#endif
