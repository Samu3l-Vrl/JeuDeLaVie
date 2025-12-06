#include "../headers/cell.hpp"
#pragma once 

class aliveCell : public Cell {
    public:
        aliveCell();
        ~aliveCell();
        
        bool getState() const override ;
        
        void setState(bool state) override;
};