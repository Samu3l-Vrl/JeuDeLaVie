#include "../headers/cell.hpp"
#pragma once 

class Rules {    
    public : 
        Rules();
        ~Rules();
        bool applyRules(bool State, int nb_neighbors);
};