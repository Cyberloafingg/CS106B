// my project

#include <iostream>
#include "console.h"
#include "gwindow.h" // for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
#include "grid.h"
void drawGrid(Grid<int> &grid);
void mirror(Grid<int> &grid);
using namespace std;

int main() {
    Grid<int> grid = {{6,1,9,4},{-2,5,8,12},{14,39,-6,18},{21,55,73,-3}};
    mirror(grid);

    return 0;
}

void mirror(Grid<int> &grid){
    Grid<int> cgrid = grid;
    for (int i = 0; i < grid.numRows(); ++i) {
        for (int j = 0; j < grid.numCols(); j++) {
            cgrid[i][j] = grid[j][i];
        }
    }
    drawGrid(cgrid);
}
void drawGrid(Grid<int> &grid){
    Grid<int> cgrid = grid;
    for (int i = 0; i < grid.numRows(); ++i) {
        for (int j = 0; j < grid.numCols(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
