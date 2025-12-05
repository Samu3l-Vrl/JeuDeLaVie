#include "../headers/alivecell.hpp"

aliveCell::aliveCell() {
    this->x = x;
    this->y = y;
    this->state = true;
}

aliveCell::aliveCell(int x, int y) {
    this->x = x;
    this->y = y;
    this->state = true;
}

aliveCell::~aliveCell() {}

int aliveCell::getX() {
    return this->x;
}

int aliveCell::getY() {
    return this->y;
}

bool aliveCell::getState() {
    return true;
}

void aliveCell::setX(int x) {
    this->x = x;
}

void aliveCell::setY(int y) {
    this->y = y;
}

void aliveCell::setState(bool state) {
    this->state = state;
}