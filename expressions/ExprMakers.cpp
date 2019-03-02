#include "ExprMakers.hpp"

Expression* getAddExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression(lita->getValue() + litb->getValue(), lita->getType());
    }
    else {
        return new AddExpr(a, b, a->getType());
    }
}

Expression* getSubExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression(lita->getValue() - litb->getValue(), lita->getType());
    }
    else {
        return new SubExpr(a, b, a->getType());
    }
}

Expression* getMulExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression(lita->getValue() * litb->getValue(), lita->getType());
    }
    else {
        return new MulExpr(a, b, a->getType());
    }
}

Expression* getDivExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression((lita->getValue() / litb->getValue()), lita->getType());
    }
    else {
        return new DivExpr(a, b, a->getType());
    }
}

Expression* getModExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression(lita->getValue() % litb->getValue(), lita->getType());
    }
    else {
        return new ModExpr(a, b, a->getType());
    }
}

Expression* getEqExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression(lita->getValue() == litb->getValue(), lita->getType());
    }
    else {
        return new EqExpr(a, b, a->getType());
    }
}

Expression* getNeqExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression(lita->getValue() != litb->getValue(), lita->getType());
    }
    else {
        return new NeqExpr(a, b, a->getType());
    }
}

Expression* getLeqExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression(lita->getValue() <= litb->getValue(), lita->getType());
    }
    else {
        return new LeqExpr(a, b, a->getType());
    }
}

Expression* getGeqExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression(lita->getValue() >= litb->getValue(), lita->getType());
    }
    else {
        return new GeqExpr(a, b, a->getType());
    }
}

Expression* getLtExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression(lita->getValue() < litb->getValue(), lita->getType());
    }
    else {
        return new LtExpr(a, b, a->getType());
    }
}

Expression* getGtExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression(lita->getValue() > litb->getValue(), lita->getType());
    }
    else {
        return new GtExpr(a, b, a->getType());
    }
}

Expression* getOrExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression(lita->getValue() || litb->getValue(), lita->getType());
    }
    else {
        return new OrExpr(a, b, a->getType());
    }
}

Expression* getAndExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->isConst() && b->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        auto litb = dynamic_cast<LiteralExpression*>(b);
        return new LiteralExpression(lita->getValue() && litb->getValue(), lita->getType());
    }
    else {
        return new AndExpr(a, b, a->getType());
    }
}

Expression* getNotExpr(Expression* a) {
    if (a->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        return new LiteralExpression(!lita->getValue(), lita->getType());
    }
    else {
        return new NotExpr(a, a->getType());
    }
}

Expression* getUnminusExpr(Expression* a) {
    if (a->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        return new LiteralExpression(lita->getValue() * -1, lita->getType());
    }
    else {
        return new UnminusExpr(a, a->getType());
    }
}

Expression *predValue(Expression *a) {
    if (a->getType() != BooleanType::getInstance() || a->getType() != CharacterType::getInstance() || a->getType() != IntegerType::getInstance()) {
        throw IncorrectTypePassed();
    }
    if (a->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        if (a->getType() == BooleanType::getInstance()) {
            if (lita->getValue() != 0) {
                return new LiteralExpression(0, lita->getType());
            }
            else {
                return new LiteralExpression(1, lita->getType());
            }
        }
        else {
            return new LiteralExpression(lita->getValue() - 1, a->getType());
        }
    }
    else {
        return new PredExpr(a, a->getType());
    }
}

Expression *succValue(Expression *a) {
    if (a->getType() != BooleanType::getInstance() || a->getType() != CharacterType::getInstance() || a->getType() != IntegerType::getInstance()) {
        throw IncorrectTypePassed();
    }
    if (a->isConst()) {
        auto lita = dynamic_cast<LiteralExpression*>(a);
        if (a->getType() == BooleanType::getInstance()) {
            if (lita->getValue() != 0) {
                return new LiteralExpression(0, lita->getType());
            }
            else {
                return new LiteralExpression(1, lita->getType());
            }
        }
        else {
            return new LiteralExpression(lita->getValue() + 1, a->getType());
        }
    }
    else {
        return new SuccExpr(a, a->getType());
    }
}

Expression* getStringLiteral(char* str) {
    std::string strVal(str);
    std::string label = symbol_table.storeString(strVal);
    return new StringLiteral(label);
}

Expression* getCharLiteral(char* character) {
    std::string chrVal(character);
    chrVal = chrVal.substr(1,chrVal.size() -1);
    if (chrVal.size() > 2) {
        throw CharTooBig();
    }
    if (chrVal[0] == '\\' && chrVal.size() == 2) {
        if (chrVal[1] == 'n'){
            return new LiteralExpression(int('\n'), CharacterType::getInstance());
        }
        if (chrVal[1] == 'r')
        {
            return new LiteralExpression(int('\r'), CharacterType::getInstance());
        }
        if (chrVal[1] == 'b')
        {
            return new LiteralExpression(int('\b'), CharacterType::getInstance());
        }
        if (chrVal[1] == 'f')
        {
            return new LiteralExpression(int('\f'), CharacterType::getInstance());
        }
        if (chrVal[1] == 't')
        {
            return new LiteralExpression(int('\t'), CharacterType::getInstance());
        }
        else {
            return new LiteralExpression(int(chrVal[1]), CharacterType::getInstance());
        }
    }
    else
    {
        return new LiteralExpression(int(chrVal[0]), CharacterType::getInstance());
    }
}
Expression* makeCharacterType(Expression* a) {
    if (a->getType() != IntegerType::getInstance()) {
        throw IncorrectTypePassed();
    }
    a->setType(CharacterType::getInstance());
    return a;
}

Expression* makeIntegerType(Expression* a) {
    if (a->getType() != CharacterType::getInstance()) {
        throw IncorrectTypePassed();
    }
    a->setType(CharacterType::getInstance());
    return a;
}

Expression* lookupLVal(std::string ident) {
    return symbol_table.lookupLVal(ident);
}

Expression* makeLValueExpr(std::string ident) {
    std::cout << ident << std::endl;
    return new LValExpr(ident);
}


void declareConsts(std::vector<std::pair<std::string, Expression*>>* IdentExprList) {
    for (auto i : *IdentExprList) {
        if (i.second->isLval()) {
            auto l = dynamic_cast<LValExpr*>(i.second);
            auto expr = symbol_table.lookupLVal(l->getIdent());
            symbol_table.declareConst(i.first, expr);
        }
        else {
            symbol_table.declareConst(i.first, i.second);
        }
    }
}
