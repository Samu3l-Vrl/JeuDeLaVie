#include "../headers/alivecell.hpp"
#include "../headers/deadcell.hpp"
#include"../headers/file.hpp"
#include "../headers/grid.hpp"
#include "../headers/print.hpp"
#include "../headers/rules.hpp"

using namespace std;
void generateFile(){

    ofstream fichier("fichier.txt", ios::out | ios::trunc); // Open file in write mode, truncating existing content
    if (!fichier) {
        cerr << "Error opening file!" << endl;
        
    }

int x = 1200; // Example dimensions
int y = 1200;
for(int i = 0;i<x;i++){
    for(int j = 0;j<y;j++){
        int a = rand() % 2; // Randomly generate 0 or 1
        fichier << a << " ";
    }
    fichier << endl;
}

    fichier.close(); // Close the file
}

int main(){
    generateFile();
    Grid g(1200,1200);
    g.initializeGrid();
    print p;  
    
    p.displayGrid(120, 120, 5, g);

    return 0;
}