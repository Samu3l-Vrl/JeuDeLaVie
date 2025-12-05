#include "../headers/grid.hpp"
#include "../headers/cell.hpp"

Grid::Grid(int width, int height) {
    this->width = width;
    this->height = height;
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
                if (grid[nx][ny].getState()) {
                    nb_neighbors++;
                }
            }
        } 
    }
    return nb_neighbors;
}