#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include "Phonebook.hpp"

using std::cout;  using std::endl;
using std::string;
using std::setw;  using std::setfill;
using std::right;

Phonebook::Phonebook() {
    numContacts = 0;
}

string Phonebook::truncate(string &field, string::size_type width) const {
    string ret;

    if (field.length() > width)
        ret = field.substr(0, width - 1) + ".";
    else
        ret = field;
    return ret;
}

void Phonebook::show() const {
    const int kNumColumns = 4;

    for (int col = 0; col < kNumColumns; ++col)
        cout << setfill('-') << setw(10) << "" << "+";
    cout << setfill(' ') << endl;

    for (int row = 0; row < numContacts; ++row) {
        string firstName = contacts[row].getFirstName();
        string lastName = contacts[row].getLastName();
        string nickname = contacts[row].getNickname();

        cout << right << setw(10) << row << "|";
        cout << right << setw(10) << truncate(firstName, 10) << "|";
        cout << right << setw(10) << truncate(lastName, 10) << "|";
        cout << right << setw(10) << truncate(nickname, 10) << "|";
        cout << endl;
    }

}

void Phonebook::show(int index) const {
    if (index < 0 || index > numContacts - 1) {
        cout << "Contact not found. " << endl;
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
