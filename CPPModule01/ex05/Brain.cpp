#include "Brain.hpp"

Brain::Brain() {
    eq = 42;
    iq = 42;
}

std::string Brain::identify() const {
    std::stringstream ss;
    ss << this;

    std::string ret;
    ss >> ret;
    for (std::string::iterator itr = ret.begin() + 2; itr != ret.end(); ++itr)
        *itr = (char)std::toupper(*itr);

    return ret;
}
