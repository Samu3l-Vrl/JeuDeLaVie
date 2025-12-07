#include"../headers/file.hpp"
#include "../headers/alivecell.hpp"
#include "../headers/deadcell.hpp"

file::file(){
}   
file::~file(){
}
void file::readFile(int width, int height, const std::string& filename, std::vector<std::vector<Cell*>>& g) {
    std::ifstream fichier(filename);
    if (!fichier) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    // Dimensionner la grille
    g.resize(height, std::vector<Cell*>(width, nullptr));

    std::string line;
    int y = 0;
    while (getline(fichier, line) && y < height) {
        std::istringstream iss(line);
        for (int x = 0; x < width; ++x) {
            int value;
            if (!(iss >> value)) {
                value = 0; // valeur par défaut si manque dans le fichier
            }
            if (value == 1)
                g[y][x] = new aliveCell();
            else
                g[y][x] = new deadCell();
        }
        y++;
    }

    fichier.close();
}
