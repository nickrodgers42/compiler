#include "register_pool.hpp"

RegisterPool::RegisterPool()
{
    for (int i = 0; i <= 9; ++i) {
        pool.push_back("$t" + std::to_string(i));
    }
    for (int i = 0; i <= 7; ++i) {
        pool.push_back("$s" + std::to_string(i));
    }
} 

RegisterPool::~RegisterPool() 
{

}

std::string RegisterPool::getRegister() 
{
    std::string reg = pool.back();
    pool.pop_back();
    return reg;
}

void RegisterPool::pushRegister(std::string reg)
{
    pool.push_back(reg);
}
