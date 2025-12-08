#include "../headers/cell.hpp"
#pragma once 

class obstacle : public Cell {
    public:
        obstacle();
        ~obstacle();
        
        bool getState() const override ;
        int getObs()const override;  
        
        void setState(bool state) override;
};