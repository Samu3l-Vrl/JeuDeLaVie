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
std::vector<std::vector<Cell>>& Grid::getGrid() {
    return grid;
}
int Grid::getWidth() {
    return width;
}
int Grid::getHeight() {
    return height;
}
void Grid::setGrid() {
    std::vector<std::vector<int>> newGrid = grid;

    for (int x = 0; x < gridWidth; ++x) {
        for (int y = 0; y < gridHeight; ++y){
            rules r;
            int nb_neighbors = countNeighbors(x, y);
            bool currentState = grid[x][y].getState();
            bool newState = r.applyRules(currentState, nb_neighbors);
            if(newState){
                alivecell c;
                newGrid[x][y] = c;
            }
                
            else{
                deadcell c;
                newGrid[x][y] = c;
            }
            
        }
        grid = newGrid;
}
}
void Grid::initializeGrid(vector<vector<Cell>>& grid) {
    file f;
    f.readFile("fichier.txt", grid);
}