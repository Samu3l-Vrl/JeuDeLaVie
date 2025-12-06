#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<random>
#include<ctime>
#include<chrono>
#include<thread>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#pragma once

class Cell {
    protected:
        
        bool state; // true for alive, false for dead 

    public:
        Cell(){}
        Cell(bool state) : state(state){}

        virtual bool getState() const = 0;


        virtual void setState(bool state) = 0;

        virtual ~Cell() = default;   // important pour des pointeurs
};

