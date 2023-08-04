#pragma once

#include <map>
#include <string>
#include <vector>

class BaseEstimator {
public:

    BaseEstimator();
    std::map<std::string, double> const get_params();
    void set_params(const std::map<std::string, double>&_params);
    void _check_n_features(std::vector<std::vector<double>>&X, bool reset);
    //void _validate_data();

    std::map<std::string, double>params;
    int n_features_in_;
    static std::map<std::string, double> valid_params;
};
