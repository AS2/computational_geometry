#include <iostream>
#include <string>

#include "input_provider/input_provider.h"
#include "problem_solver/problem_solver.h"
#include "output_provider/output_provider.h"

int main(int argc, char *argv[]) {
    // if (argc < 2) {
    //     std::cout << "Warning: file name with points! Finish process..." << std::endl;
    //     return 30; 
    // }
    // auto name = std::string(argv[1]);
    auto name = std::string("../tests/0.txt");
    
    // read points
    auto points = FileInputProvider::getPoints(name);
    
    // remove dublicates
    points = GrahamHullBuilder::removeDublicatesPoints(points);    
    
    // find points sets
    auto hull = GrahamHullBuilder::buildHull(points);
    
    // write to file
    if (argc == 3)
        FileOutputProvider::printPoints(hull, std::string(argv[2]));
    else
        FileOutputProvider::printPoints(hull);
    
    return 0;
}
