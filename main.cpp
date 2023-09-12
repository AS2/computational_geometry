#include <iostream>

#include "input_provider/input_provider.h"
#include "problem_solver/problem_solver.h"
#include "output_provider/output_provider.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Warning: file name with points! Finish process..." << std::endl;
        return 30; 
    }

    auto points = FileInputProvider::getPoints(std::string(argv[1]));    
    auto sets = SingleHashProblemSolver::solveProblem(points);

    if (argc == 3)
        FileOutputProvider::printPoints(sets, std::string(argv[2]));
    else
        FileOutputProvider::printPoints(sets);
    
    return 0;
}
