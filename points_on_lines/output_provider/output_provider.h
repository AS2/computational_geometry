#pragma once

#include <list>
#include <vector>
#include <string>
#include "../geom_primitives.h"

class FileOutputProvider {
public:
    static void printPoints(const std::list<PointsIdxsUSet>& pointsSets, 
                            const std::string& fileName=std::string("./output.txt"));
};
