#include"../headers/file.hpp"
#include "../headers/alivecell.hpp"
#include "../headers/deadcell.hpp"

file::file(){
}   
file::~file(){
}
void file::readFile(int width, int height, const std::string& filename, std::vector<std::vector<Cell*>>& g) {
    std::ifstream fichier(filename);//open file in read mode
    if (!fichier) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    g.resize(height, std::vector<Cell*>(width, nullptr));// resize grid at given dimensions

    std::string line;
    int y = 0;
    while (getline(fichier, line) && y < height) { // read file line by line
        std::istringstream iss(line);
        for (int x = 0; x < width; ++x) { // read each value in the line
            int value;
            if (!(iss >> value)) {// if reading fails, set default value to 0
                value = 0;
            }
            if (value == 1){
                g[y][x] = new aliveCell();// create alive cell
            }
            else{
                g[y][x] = new deadCell();// create dead cell
        }
    }
        y++;
    }

    fichier.close();// close file
}
