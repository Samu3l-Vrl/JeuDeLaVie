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
        }
            //return true;
        }
    }
    else {
        if (nb_neighbors == 3) {
            return true;
        }
}


if (grid[x][y] == 1) {
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    newGrid[x][y] = 0;
                }
            } else {
                if (liveNeighbors == 3) {
                    newGrid[x][y] = 1;
                }
            }