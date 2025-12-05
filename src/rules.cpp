#include "../headers/rules.hpp"

Rules::Rules() {
    this->nb_neighbors = 0;
    this->State = false;
}

Rules::~Rules() {

}

bool Rules::applyRules(bool State, int nb_neighbors) {
    this->State = State;
    this->nb_neighbors = nb_neighbors;

    if (State == true) {
        if (nb_neighbors < 2 || nb_neighbors > 3) {
            return false;
        } else if (nb_neighbors == 2 || nb_neighbors == 3) {
            return true;
        }
    }
    else {
        if (nb_neighbors == 3) {
            return true;
        }
    }
}