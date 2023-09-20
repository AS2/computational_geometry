#pragma once

#include <list>
#include <vector>
#include <string>
#include "../geom_primitives.h"

class FileOutputProvider {
public:
    static void printPoints(const std::vector<Point>& hull, 
                            const std::string& fileName=std::string("./output.txt"));
};
