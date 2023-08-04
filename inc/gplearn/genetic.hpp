#pragma once

#include "base.hpp"
#include "functions.hpp"
#include "fitness.hpp"
#include <string>
#include <set>
#include <vector>
#include <iomanip>

class BaseSymbolic: public BaseEstimator {
public:
    BaseSymbolic();
    BaseSymbolic(
        int _population_size, 
        int _hall_of_fame, int n_components, 
        int _generations, 
        int _tournament_size, 
        int _stopping_criteria,
        std::pair<double, double> _const_range, 
        std::pair<int, int> _init_depth,
        std::string _init_method,
        std::set<std::string> _function_set,
        std::string _transformer,
        std::string _metric,
        double _parsimony_coefficient, 
        double _p_crossover,
        double _p_subtree_mutation,
        double _p_hoist_mutation,
        double _p_point_mutation,
        double _p_point_replace,
        double _max_samples,
        double _class_weight,
        std::vector<std::string> _feature_names,
        bool _warm_start,
        bool _low_memory,
        int _n_jobs,
        int _verbose,
        int _random_state
        );
    void _verbose_reporter(std::map<std::string, std::vector<double>>run_details);
    void fit(std::vector<std::vector<double>>X, std::vector<double>y, std::vector<double>sample_weight);
    int population_size;
    int hall_of_fame;
    int n_components;
    int generations;
    int tournament_size;
    int stopping_criteria;
    std::pair<double, double> const_range;
    std::pair<int, int> init_depth;
    std::string init_method;
    std::set<std::string> function_set;
    std::map<std::string, _Function> _function_set;
    std::map<int, std::vector<_Function>> _arities;
    std::string transformer;
    std::string metric;
    double parsimony_coefficient; 
    double p_crossover;
    double p_subtree_mutation;
    double p_hoist_mutation;
    double p_point_mutation;
    double p_point_replace;
    double max_samples;
    double class_weight;
    std::vector<std::string> feature_names;
    bool warm_start;
    bool low_memory;
    int n_jobs;
    int verbose;
    int random_state;

}; 
