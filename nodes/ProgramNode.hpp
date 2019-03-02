#ifndef PROGRAMNODE_HPP
#define PROGRAMNODE_HPP

#include "Node.hpp"
#include "BodyNode.hpp"
#include "BlockNode.hpp"

class ProgramNode : public Node {
    private:
        BlockNode* block;
    public:
        ProgramNode(BlockNode* block) : block(block) {
            // symbol_table.enterScope();
            // if (constDecls != nullptr) {
            //     declareConsts(constDecls->getDecls());
            // }
        }
        void emit() {
            std::cout << ".text" << std::endl;
            std::cout << ".globl main" << std::endl;
            std::cout << "main:" << std::endl;
            block->emit();
        }
        ~ProgramNode() {
            delete block;
            symbol_table.emitStrings();
        };
};

#endif
