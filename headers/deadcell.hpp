#include "../headers/cell.hpp"
#pragma once 

class deadCell : public Cell {
    public:
        deadCell();
        ~deadCell();
        
        bool getState() const override ;
        int getObs()const override;
        void setState(bool state) override;
};