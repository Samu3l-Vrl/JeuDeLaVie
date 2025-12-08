#include "../headers/file.hpp"
#include "../headers/alivecell.hpp"
#include "../headers/deadcell.hpp"
#include "../headers/obstacle.hpp"

file::file() {}
file::~file() {}

void file::readFile(int width, int height, const std::string& filename, std::vector<std::vector<Cell*>>& g){// Read grid configuration from file
    std::ifstream fichier(filename);
    if (!fichier) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    int value;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            fichier >> value;

            delete g[y][x]; // Free existing cell

            if (value == 1)
                g[y][x] = new aliveCell();
            else if (value == 2)
                g[y][x] = new obstacle();
            else
                g[y][x] = new deadCell();
        }
    }

    fichier.close();
}
