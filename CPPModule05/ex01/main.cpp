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
        Form form("normal f", 42, 21);
        Bureaucrat bureaucrat("normal b", 1);
        bureaucrat.signForm(form);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Form form("normal f", 42, 21);
        Bureaucrat bureaucrat("normal b", 42);
        bureaucrat.signForm(form);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Form form("normal f", 42, 21);
        Bureaucrat bureaucrat("normal b", 43);
        bureaucrat.signForm(form);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
