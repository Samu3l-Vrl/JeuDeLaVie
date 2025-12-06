#include "../headers/alivecell.hpp"

aliveCell::aliveCell() {

    this->state = true;
}



aliveCell::~aliveCell() {}


bool aliveCell::getState() const{
    return true;
}


void aliveCell::setState(bool state) {
    this->state = state;
}