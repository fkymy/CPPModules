#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : Form("Presidential Pardon Form", 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& other)
    : Form(other) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& other) {
    if (this != &other) {
        Form::operator=(other);
    }
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& b) const {
    Form::execute(b);
    std::cout << getTarget() << " has been pardoned by  Zafod Beeblebrox"
              << std::endl;
}
