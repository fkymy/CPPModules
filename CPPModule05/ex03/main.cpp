#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"


int main() {
    Intern intern;

    Form* form1 = intern.makeForm("shrubbery creation", "test1");
    std::cout << "FORM: " << *form1 << std::endl;

    Form* form2 = intern.makeForm("robotomy request", "test2");
    std::cout << "FORM: " << *form2 << std::endl;

    Form* form3 = intern.makeForm("presidential pardon", "test3");
    std::cout << "FORM: " << *form3 << std::endl;

    ShrubberyCreationForm* form4 = static_cast<ShrubberyCreationForm *>(intern.makeForm("shrubbery creation", "test4"));
    std::cout << "FORM: " << *form4 << std::endl;

    RobotomyRequestForm* form5 = static_cast<RobotomyRequestForm *>(intern.makeForm("robotomy request", "test5"));
    std::cout << "FORM: " << *form5 << std::endl;

    delete form1;
    delete form2;
    delete form3;
    delete form4;
    delete form5;

    try {
        Form* error1 = intern.makeForm("", "test6");
        std::cout << "FORM: " << *error1 << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Form* error1 = intern.makeForm("ShrubberyCreationForm", "test7");
        std::cout << "FORM: " << *error1 << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
