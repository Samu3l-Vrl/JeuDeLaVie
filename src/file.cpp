#include"../headers/file.hpp"

file::file(){
}   
file::~file(){
}
void file::readFile(const std::string& filename, std::vector<std::vector<int>>& grid) {
    std::ifstream fichier(filename);
    if (!fichier) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    std::string line;
    while (getline(fichier, line)) {
        std::istringstream iss(line);
        std::vector<int> row;
        int value;
        while (iss >> value) {
            row.push_back(value);
        }
        grid.push_back(row);
    }
    fichier.close();
}
