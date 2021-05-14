#include <string>
#include <iostream>

#include "Contact.hpp"

Contact::Contact() {
#define X(field, prompt) field = "(none)";
    CONTACT_FIELDS
#undef X
}

void Contact::set(const std::string& fieldName, const std::string& line) {
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

const std::string& Contact::getFirstName() const {
    return firstName;
}

const std::string& Contact::getLastName() const {
    return lastName;
}

const std::string& Contact::getNickname() const {
    return nickname;
}
