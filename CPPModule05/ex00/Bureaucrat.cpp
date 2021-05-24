#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name(name), grade(grade) {
    if (grade < 1) throw Bureaucrat::GradeTooHighException();
    if (grade > 150) throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name) {
    grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        grade = other.grade;
    }
    return *this;
}

const std::string& Bureaucrat::getName() const { return name; }

int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::incrementGrade() {
    if (grade == 1) throw Bureaucrat::GradeTooHighException();
    --grade;
}

void Bureaucrat::decrementGrade() {
    if (grade == 150) throw Bureaucrat::GradeTooLowException();
    ++grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return os;
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
    : msg("Error: Bureaucrat: Grade too high") {}

Bureaucrat::GradeTooLowException::GradeTooLowException()
    : msg("Error: Bureaucrat: Grade Too Low") {}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return this->msg.c_str();
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return this->msg.c_str();
}
