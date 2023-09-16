#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <list>

#include "problem_solver.h"

std::vector<Point> SingleHashProblemSolver::removeDublicatesPoints(const std::vector<Point> &points) {
    std::unordered_map<Point, std::list<size_t>> points_index_set;

    for (size_t i = 0; i < points.size(); i++)
        if (points_index_set[points[i]].empty())
            points_index_set[points[i]].push_front(i);


    std::vector<Point> solo_points(points_index_set.size());
    size_t solo_points_pos = 0;
    for (size_t i = 0; i < points.size(); i++)
        if (points_index_set[points[i]].front() == i)
            solo_points[solo_points_pos++] = points[i];

    return solo_points;
}
    

std::list<PointsIdxsUSet> SingleHashProblemSolver::solveProblem(const std::vector<Point> &points) {
    std::list<PointsIdxsUSet> points_subsets;

    std::unordered_map<Line, PointsIdxsUSet> lines_with_points;

    // Go throw all points pairs
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            // Generate line throw 2 points
            Line new_line;

            // Construct and simplify line. Method will construct normilized (A, B, C) tuple;
            // Normilize time cost - O(log^2(B)), where B is upper bound of absolute value of points coordinate.
            new_line.ConstuctFromPoints(points[i], points[j]);

            // Insert points, which lie on some line, into one unordered_set (hash-map) of integers. 
            // 'Insert' time cost - O(1)
            if (lines_with_points[new_line].empty())
                lines_with_points[new_line].insert(i);
            lines_with_points[new_line].insert(j);
        } 
    }

    // Go throw all lines and select which one has more than 2 points on them
    // Time cost: O(N^2)
    for (auto &[_, some_set] : lines_with_points)
        if (some_set.size() > 2)
            points_subsets.push_back(some_set);

    return points_subsets;
}
