#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : Form("robotomy request", 72, 45, target) {}

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

    std::cout << "guri guri guri" << std::endl;
    if (rand() % 2)
        std::cout << getTarget() << " has been robotomized successfully"
                  << std::endl;
    else
        std::cout << getTarget() << " robotomization failed" << std::endl;
}
