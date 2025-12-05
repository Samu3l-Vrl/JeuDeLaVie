#pragma once
#include "../headers/cell.hpp"

class Grid {
    private : 
        int width;
        int height;
        int nb_neighbors;

    public : 
        Grid(int width, int height);
        ~Grid();
        int countNeighbors(int x, int y);

};