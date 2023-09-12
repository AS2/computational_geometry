#pragma once

#include <list>
#include <unordered_set>
#include <vector>
#include "../geom_primitives.h"

// Implementation of solver, which using single hash-table
// Memory using: O(N^2)
// Time using: O(N^2 * log^2(B)), where B is maximum possible absolute value of coordinate
class SingleHashProblemSolver {
public:
    static std::list<PointsIdxsUSet> solveProblem(const std::vector<Point> &);
};
