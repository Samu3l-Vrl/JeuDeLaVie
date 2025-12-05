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
        int x;
        int y;
        bool state; // true for alive, false for dead 

    public:
        Cell();
        Cell(int x, int y, bool state);
        virtual ~Cell();
        virtual int getX();
        virtual int getY();
        virtual bool getState();
        virtual void setX(int x);
        virtual void setY(int y);
        virtual void setState(bool state);
};