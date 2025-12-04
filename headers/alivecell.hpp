#pragma once 
#include "headers/cell.hpp"

class aliveCell : public Cellule {
    public:
        aliveCell();
        aliveCell(int x, int y);
        ~aliveCell();
        int getX();
        int getY();
        bool getState();
        void setX(int x);
        void setY(int y);
        void setState(bool state);
};