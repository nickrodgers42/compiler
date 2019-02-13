#include "register.hpp"

Register::Register() 
{
    reg = pool.getRegister();
}

Register::~Register()
{
    pool.pushRegister(reg);
}
