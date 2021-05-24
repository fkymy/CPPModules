#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Form form("normal", 42, 21);
        std::cout << form;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Form form("normal", 150, 1);
        std::cout << form;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Form form("error", 151, 150);
        std::cout << form;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Form form("error", 0, 1);
        std::cout << form;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Form form("form1", 42, 21);
        Bureaucrat bureaucrat("bureau1", 1);
        std::cout << bureaucrat;
        std::cout << form;
        bureaucrat.signForm(form);
        std::cout << form;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Form form("form1", 42, 21);
        Bureaucrat bureaucrat("bureau1", 42);
        std::cout << bureaucrat;
        std::cout << form;
        bureaucrat.signForm(form);
        std::cout << form;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Form form("form1", 42, 21);
        Bureaucrat bureaucrat("bureau1", 43);
        std::cout << bureaucrat;
        std::cout << form;
        bureaucrat.signForm(form);
        std::cout << form;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
