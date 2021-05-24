#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : Form("shrubbery creation", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : Form(other) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& other) {
    if (this != &other) {
        Form::operator=(other);
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& b) const {
    Form::execute(b);

    std::ofstream output(getTarget() + "_shrubbery");
    if (!output.is_open()) throw ShrubberyCreationForm::FileException();

    int height = 25;
    int width = height * 2 - 1;
    for (int i = 1; i <= height; ++i) {
        int fill = i * 2 - 1;
        output << std::setfill(' ') << std::setw((width - fill) / 2) << "";
        output << std::setfill('*') << std::setw(i * 2 - 1) << "" << std::endl;
    }
    output << std::setfill(' ') << std::setw(width / 2) << "|" << std::endl;
    output.close();
}

ShrubberyCreationForm::FileException::FileException()
    : msg("Error: ShrubberyCreationForm: File could not be opened") {}

ShrubberyCreationForm::FileException::~FileException() throw() {}

const char* ShrubberyCreationForm::FileException::what() const throw() {
    return this->msg.c_str();
}
