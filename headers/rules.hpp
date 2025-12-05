#pragma once
#include "../headers/cell.hpp"
#include "../headers/grid.hpp"

class Rules {    
    public : 
        Rules();
        ~Rules();
        bool applyRules(bool State, int nb_neighbors);
};