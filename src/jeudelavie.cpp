#include "../headers/alivecell.hpp"
#include "../headers/deadcell.hpp"
#include"../headers/file.hpp"
#include "../headers/grid.hpp"
#include "../headers/print.hpp"
#include "../headers/rules.hpp"

using namespace std;
string name = "fichier.txt";
string nametest = "glider.txt";
int x = 20; // Example dimensions
int y = 20;
void generateFile(){

    ofstream fichier(name, ios::out | ios::trunc); // Open file in write mode, deleting existing content
    if (!fichier) {
        cerr << "Error opening file!" << endl;// if the file doesn't open show Error 
        
    }


for(int i = 0;i<x;i++){
    for(int j = 0;j<y;j++){
        int a = rand() % 2; // Randomly generate 0 or 1
        fichier << a << " ";// Write to file
    }
    fichier << endl;
}

    fichier.close(); // Close the file
}

int main(){
    generateFile();// Generate the initial file
    Grid g(x,y);// Create a grid of size (x,y)
    g.initializeGrid(name);// Initialize the grid
    print p;  // Create a print object
    
    p.displayGrid(x, y, 10, g);// Display the grid 

    return 0;
}