#include"../headers/obstacle.hpp"

obstacle::obstacle(){
    this->state = false;
    this->obs = 2;
}
obstacle::~obstacle(){}
bool obstacle::getState() const {
    return false; // Obstacle cells are always considered "dead"
}
void obstacle::setState(bool state) {
    this->state = state; // Although obstacles don't change state, we keep the method for interface consistency
}
int obstacle::getObs()const{
    return obs;
}