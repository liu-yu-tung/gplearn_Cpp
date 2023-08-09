#pragma once

#include "functions.hpp"
#include <string>

class _ProgramNode: public _Function {
public:
    _ProgramNode();
    _ProgramNode& operator=(_Function f);
    _ProgramNode& operator=(int v);
    _ProgramNode& operator=(double c);
    int variable;
    double constant;
    std::string type;
};
