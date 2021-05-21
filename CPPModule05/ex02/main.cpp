#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
    srand(time(NULL));
    try {
        ShrubberyCreationForm form("target1");
        std::cout << form;
        Bureaucrat bureaucrat1("name1", 1);
        bureaucrat1.signForm(form);
        bureaucrat1.executeForm(form);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        ShrubberyCreationForm form("target2");
        std::cout << form;
        Bureaucrat bureaucrat2("name2", 139);
        bureaucrat2.signForm(form);
        bureaucrat2.executeForm(form);
    } catch ( const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        RobotomyRequestForm form("target3");
        std::cout << form;
        Bureaucrat bureaucrat3("name3", 150);
        bureaucrat3.signForm(form);
        bureaucrat3.executeForm(form);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        RobotomyRequestForm form("target1");
        std::cout << form;
        Bureaucrat bureaucrat1("name1", 1);
        bureaucrat1.signForm(form);
        bureaucrat1.executeForm(form);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        RobotomyRequestForm form("target2");
        std::cout << form;
        Bureaucrat bureaucrat2("name2", 50);
        bureaucrat2.signForm(form);
        bureaucrat2.executeForm(form);
    } catch ( const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        RobotomyRequestForm form("target3");
        std::cout << form;
        Bureaucrat bureaucrat3("name3", 150);
        bureaucrat3.signForm(form);
        bureaucrat3.executeForm(form);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        PresidentialPardonForm form("target1");
        std::cout << form;
        Bureaucrat bureaucrat1("name1", 1);
        bureaucrat1.signForm(form);
        bureaucrat1.executeForm(form);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        PresidentialPardonForm form("target2");
        std::cout << form;
        Bureaucrat bureaucrat2("name2", 20);
        bureaucrat2.signForm(form);
        bureaucrat2.executeForm(form);
    } catch ( const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        PresidentialPardonForm form("target3");
        std::cout << form;
        Bureaucrat bureaucrat3("name3", 150);
        bureaucrat3.signForm(form);
        bureaucrat3.executeForm(form);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
