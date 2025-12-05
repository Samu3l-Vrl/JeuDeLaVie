#include<fstream>
#include<iostream>
#include<random>

using namespace std;    

int main() {
    ofstream fichier("fichier.txt", ios::out | ios::trunc); // Open file in write mode, truncating existing content
    if (!fichier) {
        cerr << "Error opening file!" << endl;
        return 1;
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
    return 0;
}