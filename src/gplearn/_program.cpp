#include "_program.hpp"

_Program::_Program();
_Program::_Program(
    std::vector<_Function> function_set_, 
    std::map<std::vector<_Function>> arities_,
    std::pair<int, int> init_depth_,
    std::string init_method_,
    int n_features_,
    std::pair<double, double> const_range_,
    _Fitness metric_,
    double p_point_relace_,
    double parsimony_coefficient_,
    std::mt19937 gen_();
    std::vector<std::string> feature_names_ = "",
    std::vector<_Function> program_ = {};
    ):
    function_set{function_set_},
    arities{arities_},
    init_depth{init_depth_},
    init_method{init_method_},
    n_features{n_features_},
    const_range{const_range_},
    metric{metric_},
    p_point_relace{p_point_relace_},
    parsimony_coefficient{parsimony_coefficient_},
    gen{gen_},
    feature_names{feature_names_},
    program{program_} {};

