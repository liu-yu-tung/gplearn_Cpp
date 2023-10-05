#pragma once

#include "functions.hpp"
#include "fitness.hpp"
#include "_program_node.hpp"
#include <vector>
#include <string>
#include <map>
#include <random>

class _Program {
public:
    _Program();
    _Program(
        std::vector<_Function> function_set_, 
        std::map<int, std::vector<_Function>> arities_,
        std::pair<int, int> init_depth_,
        std::string init_method_,
        int n_features_,
        std::pair<double, double> const_range_,
        _Fitness metric_,
        double p_point_relace_,
        double parsimony_coefficient_,
        std::mt19937 random_state_,
        std::vector<std::string> feature_names_,
        std::vector<_ProgramNode> program_
        );
    std::vector<_ProgramNode> build_program(std::mt19937& random_state);
    int _depth();
    int _length();
    std::vector<double>execute(std::vector<std::vector<double>> X);


    std::vector<_Function> function_set;
    std::map<int, std::vector<_Function>> arities;
    std::pair<int, int> init_depth;
    std::string init_method;
    int n_features;
    std::pair<double, double> const_range;
    _Fitness metric;
    double p_point_relace;
    double parsimony_coefficient;
    std::vector<std::string> feature_names;
    std::vector<_ProgramNode> program;
    std::mt19937 random_state;
    //std::uniform_real_distribution<double> uni_random_state;
    std::vector<_ProgramNode> program_;
    double raw_fitness_;
    double fitness_;
    std::map<std::string, std::vector<std::string>> parents;
    double _n_samples;
    double _max_samples;
    int max_depth;
    unsigned int seed;
    // _indices_state

};
