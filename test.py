import numpy as np
import graphviz
import matplotlib.pyplot as plt
#from gplearn import SymbolicRegressor 
from gplearn.genetic import SymbolicRegressor
from gplearn.utils import check_random_state

rng = check_random_state(0)

# Training samples
X_train = rng.uniform(-1, 1, 150).reshape(50, 3)
y_train = X_train[:, 0]**2 - X_train[:, 1]**2 + X_train[:, 1] - 1 +X_train[:, 2]*-2

# Testing samples
X_test = rng.uniform(-1, 1, 100).reshape(50, 2)
y_test = X_test[:, 0]**2 - X_test[:, 1]**2 + X_test[:, 1] - 1

est_gp = SymbolicRegressor(population_size=5000,
                           generations=20, stopping_criteria=0.01,
                           p_crossover=0.7, p_subtree_mutation=0.1,
                           p_hoist_mutation=0.05, p_point_mutation=0.1,
                           max_samples=0.9, verbose=1,
                           parsimony_coefficient=0.01, random_state=5)
est_gp.fit(X_train, y_train)
print(est_gp._program)

#sub(add(-0.999, X1), mul(sub(X1, X0), add(X0, X1)))

dot_data = est_gp._program.export_graphviz()
graph = graphviz.Source(dot_data)
graph


print(est_gp._program.parents)