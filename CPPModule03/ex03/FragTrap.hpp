#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <cstdlib>
#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
public:
    FragTrap();
    explicit FragTrap(const std::string& name);
    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& other);
    ~FragTrap();

    void vaulthunter_dot_exe(std::string const & target);
};

#endif /* FRAGTRAP_HPP */
