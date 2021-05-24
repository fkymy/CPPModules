#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Form;

class Bureaucrat
{
private:
    const std::string name;
    int grade;

    Bureaucrat();

public:
    Bureaucrat(const std::string& name, int grade);
    virtual ~Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);

    const std::string& getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(Form& form);
    void executeForm(Form const & form);

    class GradeTooHighException: public std::exception
    {
    private:
        std::string msg;
    public:
        GradeTooHighException();
        virtual ~GradeTooHighException() throw();
        virtual const char* what() const throw();
    };

    class GradeTooLowException: public std::exception
    {
    private:
        std::string msg;
    public:
        GradeTooLowException();
        virtual ~GradeTooLowException() throw();
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif /* BUREAUCRAT_HPP */
