#pragma once

#include <vector>
#include <string>
#include "../geom_primitives.h"

class FileInputProvider {
public:
    static std::vector<Point> getPoints(const std::string& fileName);
};
