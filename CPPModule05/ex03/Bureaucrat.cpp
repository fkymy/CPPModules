#include "Bureaucrat.hpp"

#include "Form.hpp"

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
    if (grade - 1 < 1) throw Bureaucrat::GradeTooHighException();
    grade -= 1;
}

void Bureaucrat::decrementGrade() {
    if (grade + 1 > 150) throw Bureaucrat::GradeTooLowException();
    grade += 1;
}

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << name << " signs " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << name << " cannot sign " << form.getName() << " because "
                  << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const Form& form) {
    try {
        form.execute(*this);
        std::cout << name << " executes " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << "."
       << std::endl;
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
