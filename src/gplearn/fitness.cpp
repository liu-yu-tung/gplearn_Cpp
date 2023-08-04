#include "fitness.hpp"

_Fitness::_Fitness() {
    function = _mean_absolute_error;
    greater_is_better = false;
};

_Fitness::_Fitness(double (*_function)(std::vector<double>, std::vector<double>, std::vector<double>), bool _greater_is_better): function{_function}, greater_is_better{_greater_is_better} {}


double _mean_absolute_error(std::vector<double>y, std::vector<double>y_pred, std::vector<double>w) {
    int MAE = 0.0;
    for (auto i=0; i<y.size(); i++) {
        MAE += (std::abs(y[i]-y_pred[i]) * w[i]) / y.size();
    }
    return MAE;
}

_Fitness mean_absolute_error = _Fitness(_mean_absolute_error, false);

std::map<std::string, _Fitness> _fitness_map = {
    {"mean absolute error", mean_absolute_error}
};
