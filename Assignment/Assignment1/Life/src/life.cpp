// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header!

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "console.h"
#include "filelib.h"
#include "grid.h"
#include "gwindow.h"
#include "simpio.h"
#include "strlib.h"
#include "lifegui.h"
using namespace std;

/* -------Funtion--------- */
void printWelcome();
void read_File(string filePath, ifstream& fin);
void drawGrid(Grid<char> &grid);
void initGrid(ifstream &fin, Grid<char> &cGrid, Grid<char> &nGrid, int &row,int &col,LifeGUI& gui);
int findCount(Grid<char> &cGrid, int &i, int &j, bool flag);
void nextGrid(int &i, int &j, const int count, Grid<char> &nGrid, LifeGUI &gui);
void nextFrame(Grid<char> &cGrid, Grid<char> &nGrid, bool flag, LifeGUI &gui);
void animtion(Grid<char> &cGrid, Grid<char> &nGrid, int frames, bool flag, LifeGUI &gui);
void menu(char& option, Grid<char>& cGrid, Grid<char>& nGrid, bool wrapping, LifeGUI &gui);
bool wrapping_Indicator();

int main() {
    // TODO: Finish the program!
    /* ------ Welcome ------*/
    printWelcome();

    /* ------ Read File ------*/
    ifstream fin;
    string filePath;
    read_File(filePath, fin);

    /* ------ Init Grid ------*/
    int row, col;
    Grid<char> cGrid, nGrid;
    LifeGUI gui;
    initGrid(fin, cGrid, nGrid, row, col, gui);
    /* ------ Update Grid ------*/
    // 定位到某个格子
    // 寻找这个各自周边的八个格子
    // 对这八个各自checkBonder，如果越界返回false
    // 对于true的判断有几个X，记作count
    /*count <= 1，nGrid[i][j] = '-'
     *count = 2，nGrid[i][j] = cGrid[i][j]
     *count = 3，if cGrid[i][j] = 'X' : nGrid[i][j] = cGrid[i][j]
     *              cGrid[i][j] = '-' : nGrid[i][j] = 'X'
     *count => 4, nGrid[i][j] = '-'
     *1，4是同一种情况，2不会改变，3单例算总是'X'
    */

    char option;
    bool flag = wrapping_Indicator();
    drawGrid(cGrid);
    menu(option, cGrid, nGrid, flag, gui);
    cout << "Have a nice Life!" << endl;
    fin.close();
    return 0;
}

bool wrapping_Indicator() {
    char wrapOption;

    cout << "Should the simulation wrap around the grid (y/n)? ";
    cin >> wrapOption;

    // input validation
    while(!cin || cin.peek() != '\n') {
        cout << "Invalid input, try again.\n";
        cin.clear();
        cin.ignore(999, '\n');
        cout << "Should the simulation wrap around the grid (y/n)? ";
        cin >> wrapOption;
    }

    switch (wrapOption) {
    case 'y':
    case 'Y':
        return true;
        break;
    case 'n':
    case 'N':
        return false;
        break;
    default:
        cin.clear();
        cin.ignore(9999, '\n');
        cout << "Invalid input, try again. \n";
        return wrapping_Indicator();
        break;
    }
}



void menu(char& option, Grid<char>& cGrid, Grid<char>& nGrid, bool flag, LifeGUI &gui){
    int frames;
    cout << "A)inmate, T)ick, Q)uit? ";
    cin >> option;
    // input validation
    while (!cin || (cin.peek() != '\n')) {
        cout << "Invalid input, try again.\n";
        cin.clear();
        cin.ignore(999, '\n');
        cout << "\nA)inmate, T)ick, Q)uit? ";
        cin >> option;
    }
    switch (option) {
    case 'a':
    case 'A':
        // animation option:
        cout << "How many frames? ";
        cin >> frames;
        // input validation
        while (!cin || (cin.peek() != '\n')) {
            cout << "Invalid input, try again.\n";
            cin.clear();
            cin.ignore(999, '\n');
            cout << "How many frames? ";
            cin >> frames;
        }
        animtion(cGrid, nGrid, frames, flag, gui);
        menu(option, cGrid, nGrid, flag, gui);
        break;

    case 't':
    case 'T':
        // tick option:
        animtion(cGrid, nGrid, 1, flag, gui);
        menu(option, cGrid, nGrid, flag, gui);
        break;

    case 'q':
    case 'Q':
        // quit program
        break;

    default:
        // otherwise prompt again:
        cin.clear();
        cin.ignore(999, '\n');
        cout << "Invalid input, Try again.";
        break;
    }
}
void animtion(Grid<char> &cGrid, Grid<char> &nGrid, int frames, bool flag, LifeGUI &gui) {
    for (int i = 0; i < frames; i++){
        clearConsole();
        nextFrame(cGrid, nGrid, flag, gui);
        pause(50);
    }
}

void nextFrame(Grid<char> &cGrid, Grid<char> &nGrid, bool flag, LifeGUI &gui){
    for (int i = 0; i < cGrid.numRows(); i++) {
        for (int j = 0; j < cGrid.numCols(); j++) {
            const int kk = findCount(cGrid, i, j, flag);
            nextGrid(i, j, kk, nGrid, gui);
        }
    }
    //TEXT
    drawGrid(nGrid);
    //------copy
    cGrid = nGrid;
}



void nextGrid(int &i, int &j, const int count, Grid<char> &nGrid, LifeGUI& gui){
    if (count <= 1 || count >= 4){
        nGrid.set(i, j, '-');
        gui.drawCell(i, j, false);
    }else if(count == 3){
        nGrid.set(i, j, 'X');
        gui.drawCell(i, j, true);
    }
}

int findCount(Grid<char> &cGrid, int &i, int &j, bool flag){
    int count = 0;
    int row = cGrid.numRows();
    int col = cGrid.numCols();
    if (flag){ // wrap
        for (int k = -1; k < 2; k++){
            for (int l = -1; l < 2; l++){
                if(cGrid.inBounds((i+k+row) % row, (j+l+col) % col) && cGrid[(i+k+row) % row][(j+l+col) % col] == 'X'){
                    count++;
                }
            }
        }
        if (cGrid[i][j] == 'X') count--;
    }else{// non-wrap
        for (int k = -1; k < 2; k++){
            for (int l = -1; l < 2; l++){
                if(cGrid.inBounds(i+k, j+l) && cGrid[i+k][j+l] == 'X'){
                    count++;
                }
            }
        }
        if (cGrid[i][j] == 'X') count--;
    }
    return count;
}

void printWelcome() {
    cout << "Welcome to the CS 106B Game of Life," << endl;
    cout << "a simulation of the lifecycle of a bacteria colony." << endl;
    cout << "Cells (X) live and die by the following rules:" << endl;
    cout << "- A cell with 1 or fewer neighbors dies." << endl;
    cout << "- Locations with 2 neighbors remain stable." << endl;
    cout << "- Locations with 3 neighbors will create life." << endl;
    cout << "- A cell with 4 or more neighbors dies." << endl;
    cout << endl;
}

void read_File(string filePath, ifstream& fin) {
    while(true) {
        filePath = getLine("Grid input file name? ");
        if (!fileExists(filePath)) {
            cout << "Can't locate the file, try again.\n";
        } else {
            openFile(fin, filePath);
            break;
        }
    }
}

void drawGrid(Grid<char> &grid){
    for (int i = 0; i < grid.numRows(); i++) {
        for (int j = 0; j < grid.numCols(); j++) {
            cout << grid[i][j] << " ";
        }
        //if(i != (grid.numCols()-1)){
            cout << endl;
        //}
    }
}

void initGrid(ifstream &fin, Grid<char> &cGrid, Grid<char> &nGrid, int &row,int &col, LifeGUI& gui){
    fin >> row;
    fin >> col;
    gui.resize(row, col);
    cGrid.resize(row, col);
    for (int i = 0; i < cGrid.numRows(); i++) {
        for (int j = 0; j < cGrid.numCols(); j++) {
            fin >> cGrid[i][j];
            gui.drawCell(i, j, cGrid[i][j] == 'X');
        }
    }
    nGrid = cGrid;
}
