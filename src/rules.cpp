#include "../headers/rules.hpp"

Rules::Rules() {}

Rules::~Rules() {

}

bool Rules::applyRules(bool State, int nb_neighbors) {
   
    if (State == true) {
        if (nb_neighbors < 2 || nb_neighbors > 3) {
            return false;
        }
        else {
            return true;
        }
    }
    else {
        if (nb_neighbors == 3) {
            return true;
        }
        else {
            return false;
        }

    }
}    
