#include "../inc/base.hpp"
#include <iostream>


BaseEstimator::BaseEstimator() {
    //params.insert(std::pair<std::string, double>("test", 5.0));
} 
std::map<std::string, double> const BaseEstimator::get_params() {
    return params; 
}
void BaseEstimator::set_params(const std::map<std::string, double>&_params) {
    for (auto i : _params) {
        params[i.first] = i.second;
    }
}

void BaseEstimator::_check_n_features(std::vector<std::vector<double>>&X, bool reset) {
    int n_features = X[0].size();
    if (reset) {
        n_features_in_  = n_features;
        return;
    }
    if (n_features_in_ != n_features) {
        std::cout << "number of features conflict\n"; 
    }
}


/*
int main () {
    BaseEstimator test;
    std::map<std::string, double> params; 
    params.insert(std::pair<std::string, double>("test", 5.0));
    test.set_params(params);
    std::map<std::string, double> out = test.get_params();
    for (auto i : out) {
        std::cout << i.first << " " << i.second << "\n"; 
    }

    return 0;
}
*/
