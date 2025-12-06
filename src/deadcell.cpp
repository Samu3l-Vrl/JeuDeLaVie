#include "../headers/deadcell.hpp"

deadCell::deadCell() {
    
    this->state = true;
}


deadCell::~deadCell() {}

bool deadCell::getState() const{
    return false;
}


void deadCell::setState(bool state) {
    this->state = state;
}