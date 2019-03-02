#ifndef READSTATEMENT_HPP
#define READSTATEMENT_HPP

#include "Statement.hpp"

class ReadStatement : public Statement {
    private:
        std::vector<Expression*>* exprList;
    public:
        ReadStatement(std::vector<Expression*>* exprList) : exprList(exprList) {}
        void emit() override {
            for (auto e : *exprList) {
                if (e != nullptr) {
                    auto regA = e->emit();
                    if (e->getType() == IntegerType::getInstance() || e->getType() == BooleanType::getInstance()) {
                        std::cout << "li $v0, 5" << std::endl;
                        std::cout << "syscall" << std::endl;
                        std::cout << "add " << regA->getRegister() << ", $v0, $zero" << std::endl;
                    }
                    if (e->getType() == CharacterType::getInstance()) {
                        std::cout << "li $v0 12" << std::endl;
                        std::cout << "syscall" << std::endl;
                        std::cout << "add " << regA->getRegister() << ", $v0, $zero" << std::endl;
                    }
                    else {
                        throw IncorrectTypePassed();
                    }
                }
            }
        }
};

#endif
