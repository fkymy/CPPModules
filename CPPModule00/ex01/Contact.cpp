#include "Contact.hpp"

#include <iostream>
#include <string>

Contact::Contact() {
#define X(field, prompt) field = "(none)";
    CONTACT_FIELDS
#undef X
}

void Contact::set(const std::string& fieldName, const std::string& input) {
#define X(field, prompt)\
    if (fieldName == #field) {\
        field = input;\
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

const std::string& Contact::getFirstName() const {
    return firstName;
}

const std::string& Contact::getLastName() const {
    return lastName;
}

const std::string& Contact::getNickname() const {
    return nickname;
}
