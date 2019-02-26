#include "../register.hpp"
#include "ExprMakers.hpp"
#include "Expression.hpp"
#include "ExprValue.hpp"
#include "LiteralValue.hpp"
#include "LiteralExpression.hpp"
#include "AddExpr.hpp"
#include "SubExpr.hpp"
#include "MulExpr.hpp"
#include "DivExpr.hpp"
#include "ModExpr.hpp"
#include "../exceptions/TypeMismatch.hpp"

Expression* getAddExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->getExprValue()->isLiteral() && b->getExprValue()->isLiteral()) {
        auto lita = dynamic_cast<LiteralExpression*>(a->getExprValue());
        auto litb = dynamic_cast<LiteralExpression*>(b->getExprValue());
        return new LiteralExpression(lita->getValue() + litb->getValue());
    }
    else {
        return new AddExpr(a, b);
    }
}

Expression* getSubExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->getExprValue()->isLiteral() && b->getExprValue()->isLiteral()) {
        auto lita = dynamic_cast<LiteralExpression*>(a->getExprValue());
        auto litb = dynamic_cast<LiteralExpression*>(b->getExprValue());
        return new LiteralExpression(lita->getValue() - litb->getValue());
    }
    else {
        return new SubExpr(a, b);
    }
}

Expression* getMulExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->getExprValue()->isLiteral() && b->getExprValue()->isLiteral()) {
        auto lita = dynamic_cast<LiteralExpression*>(a->getExprValue());
        auto litb = dynamic_cast<LiteralExpression*>(b->getExprValue());
        return new LiteralExpression(lita->getValue() * litb->getValue());
    }
    else {
        return new MulExpr(a, b);
    }
}

Expression* getDivExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->getExprValue()->isLiteral() && b->getExprValue()->isLiteral()) {
        auto lita = dynamic_cast<LiteralExpression*>(a->getExprValue());
        auto litb = dynamic_cast<LiteralExpression*>(b->getExprValue());
        return new LiteralExpression(lita->getValue() / litb->getValue());
    }
    else {
        return new DivExpr(a, b);
    }
}

Expression* getModExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->getExprValue()->isLiteral() && b->getExprValue()->isLiteral()) {
        auto lita = dynamic_cast<LiteralExpression*>(a->getExprValue());
        auto litb = dynamic_cast<LiteralExpression*>(b->getExprValue());
        return new LiteralExpression(lita->getValue() % litb->getValue());
    }
    else {
        return new ModExpr(a, b);
    }
}
