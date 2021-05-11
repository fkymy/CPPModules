#include <string>
#include <iostream>

#include "Contact.hpp"

Contact::Contact() {
#define X(field, prompt) field = "(none)";
    CONTACT_FIELDS
#undef X
}

void Contact::set(std::string fieldName, std::string line) {
#define X(field, prompt)\
    if (fieldName == #field) {\
        field = line;\
        return;\
    }
    CONTACT_FIELDS
#undef X
}

void Contact::displayInfo() const {
#define X(field, prompt) std::cout << #prompt << ": " << field << std::endl;
    CONTACT_FIELDS
#undef X
}

std::string Contact::getFirstName() const {
    return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getNickname() const {
    return nickname;
}
