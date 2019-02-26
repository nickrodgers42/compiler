#include "ExprMakers.hpp"

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

Expression* getEqExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->getExprValue()->isLiteral() && b->getExprValue()->isLiteral()) {
        auto lita = dynamic_cast<LiteralExpression*>(a->getExprValue());
        auto litb = dynamic_cast<LiteralExpression*>(b->getExprValue());
        return new LiteralExpression(lita->getValue() == litb->getValue());
    }
    else {
        return new EqExpr(a, b);
    }
}

Expression* getNeqExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->getExprValue()->isLiteral() && b->getExprValue()->isLiteral()) {
        auto lita = dynamic_cast<LiteralExpression*>(a->getExprValue());
        auto litb = dynamic_cast<LiteralExpression*>(b->getExprValue());
        return new LiteralExpression(lita->getValue() != litb->getValue());
    }
    else {
        return new NeqExpr(a, b);
    }
}

Expression* getLeqExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->getExprValue()->isLiteral() && b->getExprValue()->isLiteral()) {
        auto lita = dynamic_cast<LiteralExpression*>(a->getExprValue());
        auto litb = dynamic_cast<LiteralExpression*>(b->getExprValue());
        return new LiteralExpression(lita->getValue() <= litb->getValue());
    }
    else {
        return new LeqExpr(a, b);
    }
}

Expression* getGeqExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->getExprValue()->isLiteral() && b->getExprValue()->isLiteral()) {
        auto lita = dynamic_cast<LiteralExpression*>(a->getExprValue());
        auto litb = dynamic_cast<LiteralExpression*>(b->getExprValue());
        return new LiteralExpression(lita->getValue() >= litb->getValue());
    }
    else {
        return new GeqExpr(a, b);
    }
}

Expression* getLtExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->getExprValue()->isLiteral() && b->getExprValue()->isLiteral()) {
        auto lita = dynamic_cast<LiteralExpression*>(a->getExprValue());
        auto litb = dynamic_cast<LiteralExpression*>(b->getExprValue());
        return new LiteralExpression(lita->getValue() < litb->getValue());
    }
    else {
        return new LtExpr(a, b);
    }
}

Expression* getGtExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->getExprValue()->isLiteral() && b->getExprValue()->isLiteral()) {
        auto lita = dynamic_cast<LiteralExpression*>(a->getExprValue());
        auto litb = dynamic_cast<LiteralExpression*>(b->getExprValue());
        return new LiteralExpression(lita->getValue() > litb->getValue());
    }
    else {
        return new GtExpr(a, b);
    }
}

Expression* getOrExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->getExprValue()->isLiteral() && b->getExprValue()->isLiteral()) {
        auto lita = dynamic_cast<LiteralExpression*>(a->getExprValue());
        auto litb = dynamic_cast<LiteralExpression*>(b->getExprValue());
        return new LiteralExpression(lita->getValue() || litb->getValue());
    }
    else {
        return new OrExpr(a, b);
    }
}

Expression* getAndExpr(Expression* a, Expression* b) {
    if (a->getType() != b->getType()) {
        throw TypeMismatchException();
    }
    if (a->getExprValue()->isLiteral() && b->getExprValue()->isLiteral()) {
        auto lita = dynamic_cast<LiteralExpression*>(a->getExprValue());
        auto litb = dynamic_cast<LiteralExpression*>(b->getExprValue());
        return new LiteralExpression(lita->getValue() && litb->getValue());
    }
    else {
        return new AndExpr(a, b);
    }
}

Expression* getNotExpr(Expression* a) {
    if (a->getExprValue()->isLiteral()) {
        auto lita = dynamic_cast<LiteralExpression*>(a->getExprValue());
        return new LiteralExpression(!lita->getValue());
    }
    else {
        return new NotExpr(a);
    }
}

Expression* getUnminusExpr(Expression* a) {
    if (a->getExprValue()->isLiteral()) {
        auto lita = dynamic_cast<LiteralExpression*>(a->getExprValue());
        return new LiteralExpression(lita->getValue() * -1);
    }
    else {
        return new UnminusExpr(a);
    }
}
