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

double add(double *par);
double sub(double *par);
double mul(double *par);
double div(double *par);

extern _Function add2;
extern _Function sub2;
extern _Function mul2;
extern _Function div2;

extern std::map<std::string, _Function> _function_map;
