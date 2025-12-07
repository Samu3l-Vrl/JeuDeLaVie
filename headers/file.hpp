#include "../headers/cell.hpp"
#include "../headers/grid.hpp"
#pragma once 

class file{
    public:
        file();
        ~file();
        void readFile(int width, int height, const std::string& filename, std::vector<std::vector<Cell*>>& g);
        
};