#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name(name), grade(grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name) {
    grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        grade = other.grade;
    }
    return *this;
}

const std::string& Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::incrementGrade() {
    if (grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    grade -= 1;
}

void Bureaucrat::decrementGrade() {
    if (grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    grade += 1;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Error: Bureaucrat: grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Error: Bureaucrat: grade too low");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
    return os;
}
