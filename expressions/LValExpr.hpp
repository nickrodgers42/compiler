#ifndef LVALEXPR_HPP
#define LVALEXPR_HPP

#include "Expression.hpp"

class LValExpr : public Expression {
    private:
        int offSet;
        Register* reg;
        std::string ident;
        Type* type;
        bool isConst = false;
        int value;
        std::string label;
    public:
        LValExpr(std::string ident) : ident(ident) {}
        Register* emit() {
            auto e = symbol_table.lookupLVal(ident);
            type = e->getType();
            if (e->isConst()) {
                auto litE = dynamic_cast<LiteralExpression*>(e);
                isConst = true;
                value = litE->getValue();
                if (litE->getType() == StringType::getInstance()) {
                    auto stringE = dynamic_cast<StringLiteral*>(litE);
                    label = stringE->getLabel(); 
                }
                if (type == StringType::getInstance()) {
                    auto result = new Register();
                    std::cout << "la " << result->getRegister() << " "
                            << label
                            << std::endl;
                    return result;
                }
                else {
                    auto result = new Register();
                    std::cout << "addi " << result->getRegister() << ", "
                            << "$zero"
                            << ", "
                            << value
                            << std::endl;
                    return result;
                }
            }
            else {
                if (type == StringType::getInstance()) {
                    auto regE = e->emit();
                    auto result = new Register();
                    std::cout << "la " << result->getRegister() << " (" << regE->getRegister() << ")" << std::endl;
                    delete regE;
                    return result;
                }
                else {
                    auto regE = e->emit();
                    auto result = new Register();
                    std::cout << "add " << result->getRegister() << ", " 
                            << regE->getRegister() << ", "
                            << "$zero" 
                            << std::endl;
                    delete regE;
                    return result;
                }
            }
        }
        Type* getType() override {
            return type;
        }
        bool isLval() override {
            return true;
        }
        std::string getIdent() {
            return ident;
        }
};

#endif
