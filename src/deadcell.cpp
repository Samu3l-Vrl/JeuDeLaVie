#include "../headers/deadcell.hpp"

deadCell::deadCell() {
    
    this->state = true;
    this->obs = 0;
}


deadCell::~deadCell() {}

bool deadCell::getState() const{
    return false;
}
int deadCell::getObs()const{
    return obs;
}   

void deadCell::setState(bool state) {
    this->state = state;
}