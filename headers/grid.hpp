#include "../headers/cell.hpp"
#pragma once 

class Grid {
    private : 
        int width;
        int height;
        std::vector<std::vector<Cell*>> grid;

    public : 
        Grid();
        Grid(int width, int height);
        ~Grid();
        void initializeGrid(std::string name);
        int countNeighbors(int x, int y);
        void stepGrid();
        std::vector<std::vector<Cell*>>& getGrid();
        int getWidth();
        int getHeight();
        void allocateGrid();

};



