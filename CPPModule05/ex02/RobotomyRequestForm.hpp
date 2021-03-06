#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
    RobotomyRequestForm();

public:
    RobotomyRequestForm(const std::string& target);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

    virtual void execute(const Bureaucrat& b) const;
};

#endif /* ROBOTOMYREQUESTFORM_HPP */
