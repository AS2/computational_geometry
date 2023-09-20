#include <fstream>
#include "output_provider.h"

void FileOutputProvider::printPoints(const std::vector<Point>& hull, const std::string& fileName) {
    std::ofstream fout;

    fout.open(fileName);
    
    for (auto &point : hull)
        fout << point.GetX() << " " << point.GetY() << "\n";
    
    fout.close();
    return;
}
