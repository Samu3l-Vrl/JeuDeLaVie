#include "../headers/grid.hpp"
#include "../headers/alivecell.hpp"
#include "../headers/deadcell.hpp"
#include "../headers/cell.hpp"
#include"../headers/file.hpp"
#include "../headers/rules.hpp"

Grid::Grid() {
    this->width = 0;
    this->height = 0;
}


Grid::~Grid() {

}

int Grid::countNeighbors(int x, int y) {
    int nb_neighbors = 0;
    
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;

            int nx = x + dx;
            int ny = y + dy;
                    
            if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                if (grid[nx][ny]->getState()==true) {
                    nb_neighbors++;
                }
            }
        } 
    }
    return nb_neighbors;
}
std::vector<std::vector<Cell*>>& Grid::getGrid() {
    return grid;
}
int Grid::getWidth() {
    return width;
}
int Grid::getHeight() {
    return height;
}
Grid::Grid(int width, int height) {
    this->width = width;
    this->height = height;
    
    grid.resize(width, std::vector<Cell*>(height, nullptr));
}


void Grid::allocateGrid() {
    grid.resize(width, std::vector<Cell*>(height));
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            grid[x][y] = new deadCell(); // état par défaut
        }
    }
}

void Grid::stepGrid() {
    std::vector<std::vector<Cell*>> newGrid(width, std::vector<Cell*>(height, nullptr));
    Rules r;

    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            bool currentState = grid[x][y]->getState();
            int neighbors = countNeighbors(x, y);
            bool newState = r.applyRules(currentState, neighbors);

            if (newState)
                newGrid[x][y] = new aliveCell();
            else
                newGrid[x][y] = new deadCell();
        }
    }

    // Supprimer l'ancienne grille
    for (int x = 0; x < width; ++x)
        for (int y = 0; y < height; ++y)
            delete grid[x][y];

    grid = newGrid;
}


void Grid::initializeGrid() {
    file f;
    f.readFile(width, height, "fichier.txt", grid);
}