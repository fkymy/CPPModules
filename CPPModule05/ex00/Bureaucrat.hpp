#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
private:
    const std::string name;
    int grade;

    Bureaucrat();

public:
    Bureaucrat(const std::string& name, int grade);
    ~Bureaucrat();

    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);

    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException: public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException: public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif /* BUREAUCRAT_HPP */
