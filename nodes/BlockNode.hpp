#ifndef BLOCKNODE_HPP
#define BLOCKNODE_HPP

#include <vector>

#include "../statements/Statement.hpp"

class BlockNode {
    private:
        std::vector<Statement*>* statements;
    public:
        BlockNode(std::vector<Statement*>* statements) : statements(statements) {}
        void emit() {
            for (auto s : *statements) {
                s->emit();
            }
        }
};

#endif
