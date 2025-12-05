<<<<<<< HEAD
=======
#include "../headers/cell.hpp"

>>>>>>> c4c3171 (modif grid)
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
        int countNeighbors(int x, int y);
<<<<<<< HEAD

};
=======
        void setGrid();
        std::vector<std::vector<Cell>>& getGrid();
        int getWidth();
        int getHeight();
};



>>>>>>> c4c3171 (modif grid)
