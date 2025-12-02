#include "../headers/Cellule.hpp"

Cellule::Cellule(int x, int y, bool state) {
    this->x = x;
    this->y = y;
    this->state = state;
}

int Cellule::getX() {
    return this->x;
}

int Cellule::getY() {
    return this->y;
}

bool Cellule::getState() {
    return this->state;
}

void Cellule::setX(int x) {
    this->x = x;
}

void Cellule::setY(int y) {
    this->y = y;
}

void Cellule::setState(bool state) {
    this->state = state;
}