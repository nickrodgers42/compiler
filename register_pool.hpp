#ifndef REGISTER_POOL_HPP
#define REGISTER_POOL_HPP

#include "register.hpp"

#include <vector>
#include <string>

class RegisterPool
{
    private:
        std::vector<std::string> pool;
    public:
        RegisterPool();
        std::string getRegister();
        void pushRegister(std::string);
};

#endif
