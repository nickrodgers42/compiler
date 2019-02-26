#ifndef REGISTER_HPP
#define REGISTER_HPP

#include <string>
#include <vector>

class RegisterPool {
    private:
        std::vector<std::string> pool;
        static RegisterPool* instance;
        RegisterPool() 
        {
            for (int i = 7; i >= 0; --i) {
                pool.push_back("$s" + std::to_string(i));
            }
            for (int i = 9; i >= 0; --i) {
                pool.push_back("$t" + std::to_string(i));
            }
        };
        static RegisterPool* getInstance() 
        {
            if (instance == 0) {
                instance = new RegisterPool;
            }
            return instance;
        }

        std::string getRegister() 
        {
            std::string reg = pool.back();
            pool.pop_back();
            return reg;
        }

        void pushRegister(std::string reg) 
        {
            pool.push_back(reg);
        }
        
        friend class Register;
};

class Register
{
    private:
        std::string reg;
    public:
        Register() 
        {
            RegisterPool* registerPool = RegisterPool::getInstance();
            reg = registerPool->getRegister();
        }
        ~Register() 
        {
            RegisterPool* RegisterPool = RegisterPool::getInstance();
            RegisterPool->pushRegister(reg);
        }
        std::string getRegister() {
            return reg;
        }
};

RegisterPool *RegisterPool::instance = 0;

#endif
