#pragma once

#include <string>
#include <cmath>
#include <map>

class _Function {
public: 
    _Function();

    _Function(double (*_funcptr)(double*), std::string _name, int _arity);

    double (*funcptr)(double*);
    std::string name;
    int arity;
};  

_Function make_function(double (*funcptr)(double*), std::string name, int arity, bool wrap=true);

double _protected_division(double x1, double x2);
double _protected_sqrt(double x1);
double _protected_log(double x1);
double _protected_inverse(double x1);
double _sigmoid(double x1);

double add(double x, double y);
double sub(double x, double y);
double mul(double x, double y);
double div(double x, double y);

auto add2 = _Function(add, "add", 2);
auto sub2 = _Function(sub, "sub", 2);
auto mul2 = _Function(mul, "mul", 2);
auto div2 = _Function(div, "div", 2);

std::map<std::string, _Function> _function_map = {
    "add": add2,
    "sub": sub2,
    "mul": mul2,
    "div": div2,
}
