#include "../headers/cell.hpp"
#pragma once 

class print{
public:
    print();
    void displayGrid(int width, int height,const std::vector<std::vector<Cell*>>& grid);
};