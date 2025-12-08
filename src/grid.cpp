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
            if (dx == 0 && dy == 0) continue;// Skip the cell itself

            int nx = x + dx;// Neighbor's x coordinate
            int ny = y + dy;// Neighbor's y coordinate
                    
            if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                if (grid[nx][ny]->getState()==true) {// check each neighbor is alive
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
    
    grid.resize(width, std::vector<Cell*>(height, nullptr));// Initialize grid with nullptrs
}


void Grid::allocateGrid() { // Allocate memory for each cell in the grid
    grid.resize(width, std::vector<Cell*>(height));
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            grid[x][y] = new deadCell(); 
        }
    }
}

void Grid::stepGrid() {
    std::vector<std::vector<Cell*>> newGrid(width, std::vector<Cell*>(height, nullptr));// Create a new grid for the next state
    Rules r;

    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            bool currentState = grid[x][y]->getState();// Get current state of the cell
            int neighbors = countNeighbors(x, y);// Count alive neighbors
            bool newState = r.applyRules(currentState, neighbors);// Apply rules to determine new state

            if (newState)
                newGrid[x][y] = new aliveCell();// Create a new alive cell
            else
                newGrid[x][y] = new deadCell();// Create a new dead cell
        }
    }


    for (int x = 0; x < width; ++x)
        for (int y = 0; y < height; ++y)
            delete grid[x][y];// delete the old grid 

    grid = newGrid;// Update the grid to the new state
}


void Grid::initializeGrid() {
    file f;
    f.readFile(width, height, "fichier.txt", grid);// Read initial configuration from file
}