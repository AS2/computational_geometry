#pragma once

#include <list>
#include <unordered_set>
#include <vector>
#include "../geom_primitives.h"

// Implementation of solver, which using single hash-table
// Memory using: O(N^2)
// Time using: O(N^2 * log^2(B)), where B is maximum possible absolute value of coordinate
class GrahamHullBuilder {
public:
    // Time: O(N), memory O(N)
    static std::vector<Point> removeDublicatesPoints(const std::vector<Point> &);
    static std::vector<Point> buildHull(const std::vector<Point> &);
private:
    static int doubleSquare(const Point& b, const Point& e, const Point& p);
};
