#include "../headers/cell.hpp"

#pragma once

class file{
    public:
        file();
        ~file();
        void readFile(const std::string& filename, std::vector<std::vector<bool>>& grid);
        
};