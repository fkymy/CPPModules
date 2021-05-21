#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

#include "Form.hpp"

#define FORMS \
    X(ShrubberyCreationForm, "shrubbery creation") \
    X(RobotomyRequestForm, "robotomy request") \
    X(PresidentialPardonForm, "presidential pardon")

class Intern {
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    Form* makeForm(const std::string& name, const std::string& target);

    class UnknownFormException: public std::exception {
    private:
        std::string msg;
    public:
        UnknownFormException();
        virtual ~UnknownFormException() throw();
        virtual const char* what() const throw();
    };
};

#endif /* INTERN_HPP */
