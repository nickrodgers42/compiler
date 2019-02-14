#include "registerTest.hpp"

void RegisterTest::test() 
{
    std::cout << "Executing Register Test" << std::endl;

    // Test making a register
    {
        Register* r1 = new Register();
        if (r1 == nullptr) {
            std::cout << "\tFailed to make a new register" << std::endl;
            return;
        }
        if (r1->getRegister() != "$t0") {
            std::cout << "\tDid not retrieve the expected register\n" 
                      << "\tExpected register $t0, retrieved register " 
                      << r1->getRegister()
                      << std::endl;
            return;
        }
        delete r1;
    }

    // See if we can get all registers
    {
        std::vector<std::string> registers;
        for (int i = 0; i <= 9; ++i) {
            registers.push_back("$t" + std::to_string(i));
        }
        for (int i = 0; i <= 7; ++i) {
            registers.push_back("$s" + std::to_string(i));
        }
        std::vector<Register*> holding;
        for (int i = 0; i <= 16; ++i) {
            Register* temp = new Register();
            holding.push_back(temp);
            if (registers[i] != temp->getRegister()) {
                std::cout << "\tWas not able to retrieve all registers in order\n"
                          << "\tExpected register " << registers[i] << " retrieved register "
                          << temp->getRegister()
                          << std::endl;
            }
        }
        for (int i = 0; i <= 16; ++i) 
        {
            Register* a = holding[16-i];
            delete a;
            holding.pop_back();
        }
    }

    // Test deleting registers
    {
        Register* r1 = new Register();
        Register* r2 = new Register();
        Register* r3 = new Register();
        delete r1;
        Register* r4 = new Register();
        delete r2;
        delete r3;
        Register* r5 = new Register();
        if (r4->getRegister() != "$t0") {
            std::cout << "\tDeleting Register did not sucessfully push back to the pool\n"
                      << "\tExpected register $t0, retrieved register "
                      << r4->getRegister()
                      << std::endl;
        }
        if (r5->getRegister() != "$t2") {
            std::cout << "\tRegisters did not push back to the pool in the expected order\n"
                      << "\tExpected register $t2, retrieved register " 
                      << r5->getRegister()
                      << std::endl;
        }
    } 
}
