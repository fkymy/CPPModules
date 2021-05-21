#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : Form("Shrubbery Creation Form", 145, 137) {
    this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : Form(other) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        Form::operator=(other);
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &b) const {
    Form::execute(b);

    std::ofstream output(getTarget() + "_shrubbery");
    if (!output.is_open())
        throw ShrubberyCreationForm::FileException();

    // TODO: Draw tree
    output << "TREE!!! =========>>>" << std::endl;
    output.close();
}

ShrubberyCreationForm::FileException::FileException()
    : msg("Error: Shrubbery Creation Form: File could not be opened") {}

ShrubberyCreationForm::FileException::~FileException() throw() {}

const char* ShrubberyCreationForm::FileException::what() const throw() {
    return this->msg.c_str();
}
