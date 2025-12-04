#include "../headers/cell.hpp"

Cell::Cell(int x, int y, bool state) {
    this->x = x;
    this->y = y;
    this->state = state;
}

int Cell::getX() {
    return this->x;
}

int Cell::getY() {
    return this->y;
}

bool Cell::getState() {
    return this->state;
}

void Cell::setX(int x) {
    this->x = x;
}

void Cell::setY(int y) {
    this->y = y;
}

void Cell::setState(bool state) {
    this->state = state;
}