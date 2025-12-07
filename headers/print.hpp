#include "../headers/cell.hpp"
#include "../headers/alivecell.hpp"
#include "../headers/grid.hpp"
#pragma once 

class print{
public:
    print();
    void displayGrid(int width, int height, int cellSize, Grid& g);
};