#include <iostream>
#include <string>

#include "input_provider/input_provider.h"
#include "problem_solver/problem_solver.h"
#include "output_provider/output_provider.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Warning: file name with points! Finish process..." << std::endl;
        return 30; 
    }
    
    // read points
    auto points = FileInputProvider::getPoints(std::string(argv[1]));
    
    // remove dublicates
    points = SingleHashProblemSolver::removeDublicatesPoints(points);    
    
    // find points sets
    auto sets = SingleHashProblemSolver::solveProblem(points);
    
    // write to file
    if (argc == 3)
        FileOutputProvider::printPoints(sets, std::string(argv[2]));
    else
        FileOutputProvider::printPoints(sets);
    
    return 0;
}
