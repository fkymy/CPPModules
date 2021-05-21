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

    Form* test = intern.makeForm("shrubbery creation", "test");
    std::cout << "FORM: " << *test << std::endl;

    return 0;
}
