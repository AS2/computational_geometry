#pragma once

#include <utility>
#include <numeric>
#include <functional>
#include <unordered_set>

// usefull func
inline u_int64_t CantorsHashingPair(const u_int64_t& a, const u_int64_t& b) {
    return (a + b + 1) * (a + b) / 2 + b;
}

class Point {
public:
    Point() = default;
    Point(const int64_t& x, const int64_t& y) : m_x(x), m_y(y) {}

    int64_t GetX() const {return m_x;}
    int64_t GetY() const {return m_y;}

    bool operator==(const Point &other) const { 
        return (m_x == other.m_x && m_y == other.m_y);
    }

    Point operator -(const Point& a) {
        Point tmp;
        tmp.m_x = this->m_x - a.m_x;
        tmp.m_y = this->m_y - a.m_y;
        return tmp;
    }

    inline u_int64_t lenght() const {
        return m_x * m_x + m_y * m_y;
    }
private:
    int64_t m_x, m_y;
};

template <>
class std::hash<Point>
{
public:
  u_int64_t operator()(const Point& point) const {
    return CantorsHashingPair(abs(point.GetX()), abs(point.GetY()));
  }
};
