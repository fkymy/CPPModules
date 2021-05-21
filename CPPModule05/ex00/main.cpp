#include "Bureaucrat.hpp"

int main() {
    try
    {
        Bureaucrat normal("normal", 42);
        std::cout << normal << std::endl;
        normal.incrementGrade();
        std::cout << normal << std::endl;
        normal.decrementGrade();
        std::cout << normal << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat highest("highest", 1);
        std::cout << highest << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat lowest("lowest", 150);
        std::cout << lowest << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat tooHigh("tooHigh", 0);
        std::cout << tooHigh << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat tooLow("tooLow", 151);
        std::cout << tooLow << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat highest("highest", 1);
        highest.incrementGrade();
        std::cout << highest << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat lowest("lowest", 150);
        lowest.decrementGrade();
        std::cout << lowest << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
