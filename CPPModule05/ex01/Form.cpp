#include "Form.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExec)
    : name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec) {
    isSigned = false;
    if (gradeToSign < 1) throw Form::GradeTooHighException();
    if (gradeToSign > 150) throw Form::GradeTooLowException();
    if (gradeToExec < 1) throw Form::GradeTooHighException();
    if (gradeToExec > 150) throw Form::GradeTooLowException();
}

Form::Form(const Form& other)
    : name(other.name),
      gradeToSign(other.gradeToSign),
      gradeToExec(other.gradeToExec) {
    isSigned = other.isSigned;
}

Form& Form::operator=(const Form& other) {
    if (this != &other) isSigned = other.isSigned;
    return *this;
}

Form::~Form() {}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() <= gradeToSign)
        isSigned = true;
    else
        throw Form::GradeTooLowException();
}

const std::string& Form::getName() const { return name; }

int Form::getGradeToSign() const { return gradeToSign; }

int Form::getGradeToExec() const { return gradeToExec; }

bool Form::getIsSigned() const { return isSigned; }

Form::GradeTooHighException::GradeTooHighException()
    : msg("Error: Form: Grade too high") {}

Form::GradeTooLowException::GradeTooLowException()
    : msg("Error: Form: Grade too low") {}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char* Form::GradeTooHighException::what() const throw() {
    return this->msg.c_str();
}

const char* Form::GradeTooLowException::what() const throw() {
    return this->msg.c_str();
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "form <name: " << f.getName() << ", isSigned: " << f.getIsSigned()
       << ", gradeToSign: " << f.getGradeToSign()
       << ", gradeToExec: " << f.getGradeToExec() << ">" << std::endl;
    return os;
}
