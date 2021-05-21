#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <fstream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

class ShrubberyCreationForm: public Form {
private:
    ShrubberyCreationForm();

public:
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    virtual ~ShrubberyCreationForm();

    virtual void execute(const Bureaucrat& b) const;

    class FileException: public std::exception {
    private:
        std::string msg;
    public:
        FileException();
        virtual ~FileException() throw();
        virtual const char* what() const throw();
    };
};

#endif /* SHRUBBERYCREATIONFORM_HPP */
