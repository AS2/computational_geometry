#pragma once

#include <utility>
#include <numeric>
#include <functional>
#include <unordered_set>

using Point = std::pair<int, int>;
using PointsIdxsUSet = std::unordered_set<int>;

class Line {
public:
    void ConstuctFromPoints(const Point& p1, const Point& p2) {
        // If points are same -> leave
        if (p1 == p2)
            return;
        
        // Count A, B, C
        A = p2.second - p1.second;
        B = p1.first - p2.first;
        C = -1 * (p1.first * A + p1.second * B);

        // Normalize to some form (for example like this)
        if (A < 0)
            A *= -1, B *= -1, C *= -1;
        else if (A == 0) {
            if (B < 0)
                B *= -1, C *= -1;
        }

        // Normalize by division on GCD
        int gcd;
        if (A == 0)
            gcd = std::gcd(B, C);
        else if (B == 0)
            gcd = std::gcd(A, C);
        else
            gcd = std::gcd(A, std::gcd(B, C));
        A /= gcd, B /= gcd, C /= gcd;
    }

    bool operator==(const Line &other) const
    { 
        return (A == other.A
            && B == other.B
            && C == other.C);
    }

    int GetA() const {return A;};
    int GetB() const {return B;};
    int GetC() const {return C;};
private:
    int A, B, C;
};


inline int CantorsHashingPair(const int& a, const int& b) {
    return (a + b + 1) * (a + b) / 2 + b;
}

template <>
class std::hash<Line>
{
public:
  std::size_t operator()(const Line& k) const
  {
    return abs(CantorsHashingPair(k.GetA(), CantorsHashingPair(k.GetB(), k.GetC())));
  }
};