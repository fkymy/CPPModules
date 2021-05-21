#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : Form("Robotomy Request Form", 72, 45) {
    this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : Form(other) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& other) {
    if (this != &other) {
        Form::operator=(other);
    }
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& b) const {
    Form::execute(b);

    srand(time(NULL));

    std::cout << "guri guri guri" << std::endl;
    if (rand() % 2)
        std::cout << target << " has been robotomized successfully"
                  << std::endl;
    else
        std::cout << target << " robotomization failed" << std::endl;
}
