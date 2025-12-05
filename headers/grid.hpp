#include "../headers/cell.hpp"

#pragma once
#include "../headers/cell.hpp"

class Grid {
    private : 
        int width;
        int height;
        std::vector<std::vector<Cell>> grid;

    public : 
        Grid(int width, int height);
        ~Grid();
        void initializeGrid(vector<vector<Cell>>& grid);
        int countNeighbors(int x, int y);
        void setGrid();
        std::vector<std::vector<Cell>>& getGrid();
        int getWidth();
        int getHeight();
};



