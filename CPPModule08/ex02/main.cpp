#include <iostream>
#include <stack>
#include "mutantstack.hpp"

int main() {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << std::endl;
    std::cout << "===== MY TESTS =====" << std::endl;
    std::cout << std::endl;

    {
        std::cout << "===== const_iterator =====" << std::endl;
        MutantStack<int>::const_iterator curr = mstack.begin();
        MutantStack<int>::const_iterator end = mstack.end();
        ++curr;
        --curr;
        while (curr != end)
        {
            std::cout << *curr << std::endl;
            ++curr;
        }

    }
    {
        std::cout << "===== reverse_iterator =====" << std::endl;
        MutantStack<int>::reverse_iterator curr = mstack.rbegin();
        MutantStack<int>::reverse_iterator end = mstack.rend();
        ++curr;
        --curr;
        while (curr != end)
        {
            std::cout << *curr << std::endl;
            ++curr;
        }

    }
    {
        std::cout << "===== const_reverse_iterator =====" << std::endl;
        MutantStack<int>::const_reverse_iterator curr = mstack.rbegin();
        MutantStack<int>::const_reverse_iterator end = mstack.rend();
        ++curr;
        --curr;
        while (curr != end)
        {
            std::cout << *curr << std::endl;
            ++curr;
        }

    }

    std::stack<int> s2(mstack);
    while (!s2.empty())
    {
    	std::cout << "s[" << s2.size() - 1 << "]: " << s2.top() << std::endl;
    	s2.pop();
    }

    return 0;
}
