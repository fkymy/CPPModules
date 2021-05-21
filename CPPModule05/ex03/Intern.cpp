#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) { (void)other; }

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

Form* Intern::makeForm(const std::string& name, const std::string& target) {
#define X(classname, writtenname) \
    if (name == writtenname) return new classname(target);
    FORMS
#undef X
    throw Intern::UnknownFormException();
    return NULL;
}

Intern::UnknownFormException::UnknownFormException()
    : msg("Error: Intern: Unknown form name") {}

Intern::UnknownFormException::~UnknownFormException() throw() {}

const char* Intern::UnknownFormException::what() const throw() {
    return this->msg.c_str();
}
