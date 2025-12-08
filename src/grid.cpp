#include "../headers/grid.hpp"
#include "../headers/alivecell.hpp"
#include "../headers/deadcell.hpp"
#include "../headers/obstacle.hpp"
#include "../headers/file.hpp"
#include "../headers/rules.hpp"

Grid::Grid(int width, int height)
    : width(width), height(height)
{
    grid.resize(height, std::vector<Cell*>(width, nullptr));// Initialize grid with nullptrs
    allocateGrid();
}

Grid::~Grid() {
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            delete grid[y][x];// Clean up allocated cells
}

void Grid::allocateGrid() {
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            grid[y][x] = new deadCell();// Default to dead cells
}

int Grid::countNeighbors(int x, int y) {// Count alive neighbors 
    int count = 0;

    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) continue;

            int nx = (x + dx + width)  % width;
            int ny = (y + dy + height) % height;

            if (grid[ny][nx]->getState())
                count++;
        }
    }

    return count;
}

void Grid::stepGrid() {// Advance the grid by one generation
    std::vector<std::vector<Cell*>> newGrid(height, std::vector<Cell*>(width));
    Rules r;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            if (grid[y][x]->getObs() == 2) {
                newGrid[y][x] = new obstacle();
                continue;
            }

            bool alive = grid[y][x]->getState();// Current state
            int neighbors = countNeighbors(x, y);// Count alive neighbors
            bool next = r.applyRules(alive, neighbors);// Determine next state

            if (next) newGrid[y][x] = new aliveCell();// Alive in next generation
            else     newGrid[y][x] = new deadCell();// Dead in next generation
        }
    }

    // delete old grid
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            delete grid[y][x];

    grid = newGrid;
}

void Grid::initializeGrid(std::string name) {// Initialize grid from file
    file f;
    f.readFile(width, height, name, grid);
}

std::vector<std::vector<Cell*>>& Grid::getGrid() { return grid; }// Accessor for the grid
int Grid::getWidth() { return width; }// Accessor for width
int Grid::getHeight() { return height; }// Accessor for height
