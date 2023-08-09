#include "_program_node.hpp"

_ProgramNode::_ProgramNode(): _Function() {
    type = "NaN";
}

_ProgramNode& _ProgramNode::operator=(_Function f) {
    type = "function";
    funcptr = f.funcptr;
    name = f.name;
    arity = f.arity;
    return *this;
}

_ProgramNode& _ProgramNode::operator=(int v) {
    type = "variable";
    variable = v;
    return *this;
}

_ProgramNode& _ProgramNode::operator=(double c) {
    type = "constant";
    constant = c;
    return *this;
}
