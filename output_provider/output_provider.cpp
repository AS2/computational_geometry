#include <fstream>
#include "output_provider.h"

void FileOutputProvider::printPoints(const std::list<PointsIdxsUSet>& pointsSets, const std::string& fileName) {
    std::ofstream fout;

    fout.open(fileName);
    
    // write lines
    for (auto &some_set : pointsSets) {
        for (auto &indx : some_set)
            fout << indx << " ";
        fout << "\n";
    }
    
    fout.close();
    return;
}
