#include"../headers/file.hpp"
#include "../headers/alivecell.hpp"
#include "../headers/deadcell.hpp"
file::file(){
}   
file::~file(){
}
void file::readFile(const std::string& filename, std::vector<std::vector<Cell*>>& grid) {
    std::ifstream fichier(filename);
    if (!fichier) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    std::string line;
    while (getline(fichier, line)) {
        std::istringstream iss(line);
        std::vector<Cell*> row;
        int value;
        while (iss >> value) {
            if (value ==1){
                Cell* v = new aliveCell(); 
                row.push_back(v);
            }
            else{
                Cell* v = new deadCell(); 
                row.push_back(v);
            }
        }
        grid.push_back(row);
    }
    fichier.close();
}
