#ifndef CONTACT_H
#define CONTACT_H

#include <string>

const int kNumContacts = 8;

#define CONTACT_FIELDS \
    X(firstName, "first name") \
    X(lastName, "last name") \
    X(nickname, "nickname") \
    X(login, "login") \
    X(postalAddress, "postal address") \
    X(emailAddress, "email address") \
    X(phoneNumber, "phone number") \
    X(birthdayDate, "birthday date") \
    X(favoriteMeal, "favorite meal") \
    X(underwearColor, "underwear color") \
    X(darkestSecret, "darkest secret")

class Contact {
public:
    Contact();

    void set(std::string fieldName, std::string line);
    void displayInfo() const;
    int getFields();
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;

private:
#define X(field, prompt) std::string field;
    CONTACT_FIELDS
#undef X
};

#endif
