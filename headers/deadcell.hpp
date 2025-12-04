#pragma once 
#include "headers/cell.hpp"

class deadCell : public Cell {
    public:
        deadCell();
        deadCell(int x, int y);
        ~deadCell();
        int getX();
        int getY();
        bool getState();
        void setX(int x);
        void setY(int y);
        void setState(bool state);
};