<<<<<<< HEAD
#pragma once

class Grid {
    private : 
        int width;
        int height;
        int nb_neighbors;

    public : 
        Grid(int width, int height);
        ~Grid();
        int countNeighbors(int x, int y);

};
=======
#include "../headers/cell.hpp"
>>>>>>> b8667a4 (ajout de file et main ainsi que le generateur de fichier)
