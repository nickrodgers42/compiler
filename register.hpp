#ifndef REGISTER_HPP
#define REGISTER_HPP

#include <string>

#include "register_pool.hpp"

extern RegisterPool pool;

class Register
{
    private:
        std::string reg;
    public:
        Register();
        ~Register();
};

#endif
