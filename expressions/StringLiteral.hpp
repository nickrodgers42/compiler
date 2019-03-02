#ifndef STRINGLITERAL_HPP
#define STRINGLITERAL_HPP

#include "LiteralExpression.hpp"

class StringLiteral : public LiteralExpression {
    private:
        std::string label;
    public:
        StringLiteral(std::string label) : LiteralExpression(0, StringType::getInstance()), label(label) {}
        Register* emit() {
            auto result = new Register();
            std::cout << "la " << result->getRegister() << " "
                      << label
                      << std::endl;
            return result;
        }
        std::string getLabel() {
            return label;
        }
};

#endif
