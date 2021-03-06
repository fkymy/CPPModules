#include "Form.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExec,
           const std::string& target)
    : name(name),
      isSigned(false),
      gradeToSign(gradeToSign),
      gradeToExec(gradeToExec),
      target(target) {
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
    target = other.target;
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        isSigned = other.isSigned;
        target = other.target;
    }
    return *this;
}

Form::~Form() {}

const std::string& Form::getName() const { return name; }

bool Form::getIsSigned() const { return isSigned; }

int Form::getGradeToSign() const { return gradeToSign; }

int Form::getGradeToExec() const { return gradeToExec; }

const std::string& Form::getTarget() const { return target; }

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeToSign)
        throw Form::GradeTooLowException();
    isSigned = true;
}

void Form::execute(const Bureaucrat& b) const {
    if (!isSigned)
        throw Form::NotSignedException();
    if (b.getGrade() > gradeToExec)
        throw Form::GradeTooLowException();
}

Form::GradeTooHighException::GradeTooHighException()
    : msg("Error: Form: Grade too high") {}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

const char* Form::GradeTooHighException::what() const throw() {
    return this->msg.c_str();
}

Form::GradeTooLowException::GradeTooLowException()
    : msg("Error: Form: Grade too low") {}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char* Form::GradeTooLowException::what() const throw() {
    return this->msg.c_str();
}

Form::NotSignedException::NotSignedException()
    : msg("Error: Form: Not signed") {}

Form::NotSignedException::~NotSignedException() throw() {}

const char* Form::NotSignedException::what() const throw() {
    return this->msg.c_str();
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form <name: " << f.getName() << ", isSigned: " << f.getIsSigned()
       << ", gradeToSign: " << f.getGradeToSign()
       << ", gradeToExec: " << f.getGradeToExec()
       << ", target: " << f.getTarget() << ">" << std::endl;
    return os;
}
