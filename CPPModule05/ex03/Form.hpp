#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExec;

    Form();

protected:
    std::string target;

public:
    Form(const std::string& name, int gradeToSign, int gradeToExec);
    virtual ~Form();

    Form(const Form& other);
    Form& operator=(const Form& other);

    const std::string& getName() const;
    int getGradeToSign() const;
    int getGradeToExec() const;
    bool getIsSigned() const;
    const std::string& getTarget() const;
    void beSigned(const Bureaucrat& b);
    virtual void execute(const Bureaucrat& b) const;

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

    class NotSignedException : public std::exception
    {
    private:
        std::string msg;
    public:
        NotSignedException();
        virtual ~NotSignedException() throw();
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif /* FORM_HPP */
