#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <array>
#include <utility>

#include "Contact.hpp"

class Phonebook {
public:
    Phonebook();

    void show() const;
    void show(int index) const;
    bool add(const Contact& contact);
    int getNumContacts() const;

private:
    const static int kNumContacts = 8;
    int numContacts;
    Contact contacts[kNumContacts];

    std::string truncate(const std::string& field,
                         std::string::size_type width) const;
};

#endif
