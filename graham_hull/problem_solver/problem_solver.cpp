#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <list>

#include "problem_solver.h"

std::vector<Point> GrahamHullBuilder::removeDublicatesPoints(const std::vector<Point> &points) {
    std::unordered_map<Point, std::list<u_int64_t>> points_index_set;

    for (u_int64_t i = 0; i < points.size(); i++)
        if (points_index_set[points[i]].empty())
            points_index_set[points[i]].push_front(i);


    std::vector<Point> solo_points(points_index_set.size());
    u_int64_t solo_points_pos = 0;
    for (u_int64_t i = 0; i < points.size(); i++)
        if (points_index_set[points[i]].front() == i)
            solo_points[solo_points_pos++] = points[i];

    return solo_points;
}


int64_t GrahamHullBuilder::doubleSquare(const Point& b, const Point& e, const Point& p) {
    auto pos = b.GetX() * e.GetY() + b.GetY() * p.GetX() + e.GetX() * p.GetY();
    auto neg = p.GetX() * e.GetY() + b.GetY() * e.GetX() + b.GetX() * p.GetY();

    return pos - neg;
}


std::vector<Point> GrahamHullBuilder::buildHull(const std::vector<Point> &points) {
    // Step 0: If there are not enought points - return them all (cauze thay are all elements of hull)
    if (points.size() < 3) {
        if (points.size() != 2)
            return points;
        // Swap 2 points for lil optimization (we dont need to call sort algorithm like in "step 2")
        if (points[0].GetY() > points[1].GetY() || 
            (points[0].GetY() == points[1].GetY() && points[0].GetX() > points[1].GetX())) {
            std::vector<Point> result = {points[1], points[0]};
            return result;
        }
        else
            return points;
    }

    // Step 1: take the leftest downest point and push it to begin of array
    auto points_tmp = points;
    
    for (u_int64_t i = 1; i < points_tmp.size(); i++)
        if (points_tmp[0].GetY() > points_tmp[i].GetY() || 
            (points_tmp[0].GetY() == points_tmp[i].GetY() && points_tmp[0].GetX() > points_tmp[i].GetX())) {
            auto tmp = points_tmp[i];
            points_tmp[i] = points_tmp[0];
            points_tmp[0] = tmp;
        }
    
    // Step 2: sort all points by polar angel from start point
    Point start_point = points_tmp[0];
    std::sort(points_tmp.begin() + 1, 
            points_tmp.end(), 
            [&](Point a, Point b){
                return doubleSquare(start_point, a, b) > 0 || 
                    (doubleSquare(start_point, a, b) == 0 && 
                    (b - start_point).lenght() > (a - start_point).lenght());
            });
    
    // Step 3: goes from all sorted points and fill the list of 
    std::vector<Point> hull;
    hull.reserve(points_tmp.size());

    hull.push_back(points_tmp[0]);
    hull.push_back(points_tmp[1]);

    for (u_int64_t i = 2; i < points_tmp.size(); i++) {
        while (hull.size() >= 2 && doubleSquare(hull[hull.size() - 2], hull[hull.size() - 1], points_tmp[i]) <= 0)
            hull.pop_back();
        hull.push_back(points_tmp[i]);
    }

    return hull;
}
