#include "../inc/genetic.hpp"

BaseSymbolic::BaseSymbolic(): BaseEstimator() {
    population_size = 1000;
    hall_of_fame = -1;
    n_components = -1;
    generations = 20;
    tournament_size = 20;
    stopping_criteria = 0.0;
    const_range = {-1, 1};
    init_depth = {2, 6};
    init_method = "half and half";
    function_set = {"add", "sub", "mul", "div"};
    transformer = "";
    metric = "mean absolute error";
    parsimony_coefficient = 0.001;
    p_crossover = 0.9;
    p_subtree_mutation = 0.01;
    p_hoist_mutation = 0.01;
    p_point_mutation = 0.01;
    p_point_replace = 0.01;
    max_samples = 1.0;
    warm_start = false;
    low_memory = false;
    n_jobs = 1;
    verbose = 0;
    random_state = 0;
}
BaseSymbolic::BaseSymbolic(
    int _population_size, 
    int _hall_of_fame,
    int _n_components, 
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
    ) : 
    BaseEstimator(),
    population_size{_population_size}, 
    hall_of_fame{_hall_of_fame},
    n_components{_n_components}, 
    generations{_generations}, 
    tournament_size{_tournament_size}, 
    stopping_criteria{_stopping_criteria},
    const_range{_const_range}, 
    init_depth{_init_depth},
    init_method{_init_method},
    function_set{_function_set},
    transformer{_transformer},
    metric{_metric},
    parsimony_coefficient{_parsimony_coefficient}, 
    p_crossover{_p_crossover},
    p_subtree_mutation{_p_subtree_mutation},
    p_hoist_mutation{_p_hoist_mutation},
    p_point_mutation{_p_point_mutation},
    p_point_replace{_p_point_replace},
    max_samples{_max_samples},
    class_weight{_class_weight},
    feature_names{_feature_names},
    warm_start{_warm_start},
    low_memory{_low_memory},
    n_jobs{_n_jobs},
    verbose{_verbose},
    random_state{_random_state} {
    }

void BaseSymbolic::_verbose_reporter(std::map<std::string, std::vector<double>>run_details) {
    if (run_details.empty()) {
        printf("    |   Population Average    |             Best Indevidual              |\n"); 
        printf("---- ------------------------- ------------------------------------------ ----------\n");
        printf("Gen   Length          Fitness   Length          Fitness      OOB Fitness  Time Left\n");  
    }
    else {
        int generation(-1), best_length(-1);
        double generation_time(0.0), average_length(0.0), average_fitness(0.0), best_fitness(0.0);
        if (!run_details["generation"].empty()) generation  = run_details["generation"].back(); 
        if (!run_details["generation_time"].empty()) generation_time = run_details["generation_time"].back();
        if (!run_details["average_length"].empty()) average_length = run_details["average_length"].back();
        if (!run_details["average_fitness"].empty()) average_fitness = run_details["avergage_fitness"].back();
        if (!run_details["best_length"].empty()) best_length = run_details["best_length"].back();
        if (!run_details["best_fitness"].empty()) best_fitness = run_details["best_fitness"].back();
        char time_scale = 'm';
        double remaining_time = (generations - generation - 1 ) * generation_time;
        if (remaining_time > 60.0) remaining_time /= 60.0; 
        else time_scale = 's';
        double oob_fitness(-1.0);
        if (max_samples < 1.0) {
            if (!run_details["best_oob_fitness"].empty()) oob_fitness = run_details["best_oob_fitness"].back();
        }

        printf("%4d %8.2f %16f %8d %16f", generation, average_length, average_fitness, best_length, best_fitness);
        if (oob_fitness < 0.0) printf(" %16s ", "N/A");
        else printf(" %16.2f", oob_fitness);
        printf("%10.2f%c\n", remaining_time, time_scale);
        
    }
}
void BaseSymbolic::fit(std::vector<std::vector<double>>X, std::vector<double>y, std::vector<double>sample_weight) {
    // skip most validation
    int hall_of_fame_ = hall_of_fame;
    
    if (hall_of_fame_ == -1) hall_of_fame_ = population_size;
    else if (hall_of_fame_ > population_size || hall_of_fame_ < 1) printf("hall_of_fame must be less than or equal to population_siz\n");
    int n_components_ = n_components;
    if (n_components_ == -1) n_components_ = hall_of_fame_;
    if (n_components_ > hall_of_fame_ || n_components_ < 1) printf("n_components must be less than or equal to hall_of_fame.\n");

    _function_set.clear();
    for (auto &i : function_set) {
    }


}
