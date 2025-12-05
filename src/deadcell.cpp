#include "../headers/deadcell.hpp"

deadCell::deadCell() {
    this->x = x;
    this->y = y;
    this->state = true;
}

deadCell::deadCell(int x, int y) {
    this->x = x;
    this->y = y;
    this->state = true;
}

deadCell::~deadCell() {}

int deadCell::getX() {
    return this->x;
}

int deadCell::getY() {
    return this->y;
}

bool deadCell::getState() {
    return false;
}

void deadCell::setX(int x) {
    this->x = x;
}

void deadCell::setY(int y) {
    this->y = y;
}

void deadCell::setState(bool state) {
    this->state = state;
}