#pragma once

#include <vector>
#include <string>
#include <map>

class _Fitness {
public:
    _Fitness();
    _Fitness(double (*_function)(std::vector<double>, std::vector<double>, std::vector<double>), bool _greater_is_better);
    double (*function)(std::vector<double>, std::vector<double>, std::vector<double>);
    bool greater_is_better;

};

double _mean_absolute_error(std::vector<double>y, std::vector<double>y_pred, std::vector<double>w);

extern _Fitness mean_absolute_error;
extern std::map<std::string, _Fitness> _fitness_map;
