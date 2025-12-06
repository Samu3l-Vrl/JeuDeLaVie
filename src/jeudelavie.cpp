#include "../headers/alivecell.hpp"
#include "../headers/deadcell.hpp"
#include"../headers/file.hpp"
#include "../headers/grid.hpp"
#include "../headers/print.hpp"
#include "../headers/rules.hpp"

int main(){
    Grid g(1200,1200);
    g.initializeGrid();
    print p;
    p.displayGrid(1200,1200,g.getGrid());
    for(int i=0;i<1000;i++){
    g.stepGrid();
    p.displayGrid(1200,1200,g.getGrid());
}
    return 0;
}