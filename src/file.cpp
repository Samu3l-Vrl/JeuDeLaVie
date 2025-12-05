#include"../headers/file.hpp"

file::file(){
}   
file::~file(){
}
void file::readFile(const std::string& filename, std::vector<std::vector<bool>>& grid) {
    std::ifstream fichier(filename);
    if (!fichier) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    std::string line;
    while (getline(fichier, line)) {
        std::istringstream iss(line);
        std::vector<cell> row;
        int value;
        while (iss >> value) {
            if (value ==1){
                aliveCell v;
                row.push_back(v);
            }
            else{
                deadCell v;
                row.push_back(v);
            }
        }
        grid.push_back(row);
    }
    fichier.close();
}
