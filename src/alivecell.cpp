#include "../headers/alivecell.hpp"

aliveCell::aliveCell() {

    this->state = true;
    this->obs = 1;
}



aliveCell::~aliveCell() {}


bool aliveCell::getState() const{
    return true;
}
int aliveCell::getObs()const {
    return obs;
}

void aliveCell::setState(bool state) {
    this->state = state;
}