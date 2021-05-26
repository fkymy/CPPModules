#include <exception>
#include <string>

class ExampleException: public std::invalid_argument {
    public: ExampleException(const std::string& msg);
};

ExampleException::ExampleException(const std::string& msg) : std::invalid_argument(msg) {}

