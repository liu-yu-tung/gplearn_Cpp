#include "functions.hpp"

_Function add2 = _Function(add, "add", 2);
_Function sub2 = _Function(sub, "sub", 2);
_Function mul2 = _Function(mul, "mul", 2);
_Function div2 = _Function(div, "div", 2);

std::map<std::string, _Function> _function_map = {
    {"add", add2},
    {"sub", sub2},
    {"mul", mul2},
    {"div", div2}
};


_Function::_Function():arity{0} {}

_Function::_Function(double (*_funcptr)(double*), std::string _name, int _arity) : funcptr{_funcptr}, name{_name}, arity{_arity} {}

_Function make_function(double (*funcptr)(double*), std::string name, int arity, bool wrap) {
    return _Function(*funcptr, name, wrap); 
}
double _protected_division(double x1, double x2) {
    return x2>0.001?(x1/x2):1.0;
}
double _protected_sqrt(double x1) {
    return std::sqrt(std::abs(x1));
}
double _protected_log(double x1) {
    return std::abs(x1)>0.001?(std::log(std::abs(x1))):0.0;
}
double _protected_inverse(double x1) {
    return std::abs(x1)>0.001?1/x1:0.0;
}
double _sigmoid(double x1) {
    return 1 / (1 + std::exp(-x1));
}

double add(double *par) {
    return par[0] + par[1];
}
double sub(double *par) {
    return par[0] - par[1];
}
double mul(double *par) {
    return par[0] * par[1];
}
double div(double *par) {
    return par[0] / par[1];
}


