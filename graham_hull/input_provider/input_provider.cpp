#include <iostream>
#include <fstream>
#include <sstream>
#include "input_provider.h"

std::vector<Point> FileInputProvider::getPoints(const std::string& fileName) {
    std::fstream fin;
    fin.open(fileName);
    
    // read lines count
    std::string file_line;
    u_int64_t points_cnt;
    std::getline(fin, file_line);
    std::istringstream iss(file_line);
    iss >> points_cnt;
    std::vector<Point> points(points_cnt);

    // read lines    
    u_int64_t line_indx = 0;
    while (std::getline(fin, file_line)) {
        std::istringstream iss(file_line);
        int64_t x_coord, y_coord;

        // print bad line index
        if (!(iss >> x_coord >> y_coord))
            throw std::runtime_error((std::string("Bad argument in #") + std::to_string(line_indx + 1) + std::string("line!")).c_str());            
        
        points[line_indx] = {x_coord, y_coord};
        line_indx++;
    }

    fin.close();
    return points;
}
