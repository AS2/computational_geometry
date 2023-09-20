#pragma once

#include <utility>
#include <numeric>
#include <functional>
#include <unordered_set>

// usefull func
inline size_t CantorsHashingPair(const size_t& a, const size_t& b) {
    return (a + b + 1) * (a + b) / 2 + b;
}

// Point class
using PointsIdxsUSet = std::unordered_set<int>;

class Point {
public:
    Point() = default;
    Point(const int& x, const int& y) : m_x(x), m_y(y) {}

    int GetX() const {return m_x;}
    int GetY() const {return m_y;}

    bool operator==(const Point &other) const { 
        return (m_x == other.m_x && m_y == other.m_y);
    }
private:
    int m_x, m_y;
};

template <>
class std::hash<Point>
{
public:
  std::size_t operator()(const Point& point) const {
    return CantorsHashingPair(abs(point.GetX()), abs(point.GetY()));
  }
};

class Line {
public:
    void ConstuctFromPoints(const Point& p1, const Point& p2) {
        // If points are same -> leave
        if (p1 == p2)
            return;
        
        // Count A, B, C
        A = p2.GetY() - p1.GetY();
        B = p1.GetX() - p2.GetX();
        C = -1 * (p1.GetX() * A + p1.GetY() * B);

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

    bool operator==(const Line &other) const { 
        return (A == other.A && B == other.B && C == other.C);
    }

    int GetA() const {return A;};
    int GetB() const {return B;};
    int GetC() const {return C;};
private:
    int A, B, C;
};

template <>
class std::hash<Line>
{
public:
  std::size_t operator()(const Line& k) const {
    return CantorsHashingPair(abs(k.GetA()), CantorsHashingPair(abs(k.GetB()), abs(k.GetC())));
  }
};