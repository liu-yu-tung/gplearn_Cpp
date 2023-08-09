#include "_program.hpp"

_Program::_Program() {
    seed = 1;
    std::mt19937 rng(seed);
    random_state = rng;
    program = build_program(random_state);
    printf("no params\n");
};
_Program::_Program(
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
    std::vector<std::string> feature_names_ = {""},
    std::vector<_ProgramNode> program_ = {}
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
    random_state{random_state_},
    feature_names{feature_names_},
    program{program_} {
        init_depth_.second += 1;
        if (program.size() != 0) {
        
        }
        else {
            program = build_program(random_state);
        }
        raw_fitness_ = 0.0;
        fitness_ = 0.0;
        parents = {};
        _max_samples = 0.0;

    };

std::vector<_ProgramNode> _Program::build_program(std::mt19937& random_state ) {
    std::vector<_ProgramNode> newProgram;
    std::string method;
    if (init_method == "half and half") method = random_state()%2 ? "full" : "grow";
    else method = init_method;

    max_depth = random_state()%(init_depth.second - init_depth.first)+init_depth.first;
    int function_idx = random_state()%(function_set.size());

    _ProgramNode function;
    function = function_set[function_idx];
    newProgram.push_back(function);
    std::vector<int> terminal_stack;
    terminal_stack.push_back(function.arity);
    while (terminal_stack.size() != 0) {
        int depth = terminal_stack.size();
        int choice = n_features + function_set.size();
        choice = random_state()%choice;

        if ((depth < max_depth) && (method == "full" || choice <= function_set.size())) {
            function_idx = random_state()%function_set.size();
            function = function_set[function_idx];
            newProgram.push_back(function);
            terminal_stack.push_back(function.arity);
        }
        else {
            _ProgramNode terminal;
            if (const_range.second - const_range.first != 0.0) {
                terminal = (int)random_state()%(n_features + 1); 
            }
            else {
                terminal = (int)random_state()%n_features;
            }
            if (terminal.variable == n_features) {
                std::uniform_real_distribution<> uni_random_state(const_range.first, const_range.second);
                terminal = fmod(random_state(), const_range.second - const_range.first) + const_range.first;
            }
            newProgram.push_back(terminal);
            terminal_stack.back() -= 1;
            while (terminal_stack.back() == 0) {
                terminal_stack.pop_back();
                if (terminal_stack.size() == 1) {
                    return newProgram;
                }
            }
        }
    }
    return newProgram;

}
int _Program::_depth() {
    std::vector<int> terminals = {0};
    int depth = 1;
    for (auto node : program) {
        if (node.type == "function") {
            terminals.push_back(node.arity);
            depth = terminals.size()>depth?terminals.size():depth; 
        }
        else {
            terminals.back() -= 1;
            while (terminals.back() == 0) {
                terminals.pop_back();
                terminals.back() -= 1;
            }
        }
    } 
    return depth;
}
int _Program::_length() {
    return program.size();
}
