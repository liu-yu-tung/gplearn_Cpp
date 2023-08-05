#pragma once

#include "functions.hpp"
#include "fitness.hpp"
#include <vector>
#include <string>
#include <map>
#include <random>

class _Program {
public:
    _Program();
    _Program(
        std::vector<_Function> function_set_, 
        std::map<std::string, std::vector<_Function>> arities_,
        std::pair<int, int> init_depth_,
        std::string init_method_,
        int n_features_,
        std::pair<double, double> const_range_,
        _Fitness metric_,
        double p_point_relace_,
        double parsimony_coefficient_,
        std::mt19937 gen_(),
        std::vector<std::string> feature_names_ = {""},
        std::vector<_Function> program_ = {}
        );
    std::vector<_Function> function_set;
    std::map<std::string, std::vector<_Function>> arities;
    std::pair<int, int> init_depth;
    std::string init_method;
    int n_features;
    std::pair<double, double> const_range;
    _Fitness metric;
    double p_point_relace;
    double parsimony_coefficient;
    std::vector<std::string> feature_names;
    std::vector<_Function> program;
    std::mt19937 gen();
    std::vector<_Function> program_;

};
