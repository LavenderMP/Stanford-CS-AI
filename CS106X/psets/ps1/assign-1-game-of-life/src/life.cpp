/**
 * File: life.cpp
 * --------------
 * Implements the Game of Life.
 */

#include <iostream>  // for cout
using namespace std;

#include "console.h" // required of all files that contain the main function
#include "simpio.h"  // for getLine
#include "gevents.h" // for mouse event detection
#include "strlib.h"

#include "life-constants.h"  // for kMaxAge
#include "life-graphics.h"   // for class LifeDisplay


/**
 * Import functions
 *
 */
static bool isOccupied();
static void randomSize(int minrow, int maxrow, int mincol, int maxcol, int& rowsize, int& colsize);
static int initAge(int kMaxAge);

/**
 * Initialize constant values
 */

const int MINROW = 40;
const int MAXROW = 60;
const int MINCOL = 40;
const int MAXCOL = 60;





/**
 * Function: welcome
 * -----------------
 * Introduces the user to the Game of Life and its rules.
 */

static void welcome() {
    cout << "Welcome to the game of Life, a simulation of the lifecycle of a bacteria colony." << endl;
    cout << "Cells live and die by the following rules:" << endl << endl;
    cout << "\tA cell with 1 or fewer neighbors dies of loneliness" << endl;
    cout << "\tLocations with 2 neighbors remain stable" << endl;
    cout << "\tLocations with 3 neighbors will spontaneously create life" << endl;
    cout << "\tLocations with 4 or more neighbors die of overcrowding" << endl << endl;
    cout << "In the animation, new cells are dark and fade to gray as they age." << endl << endl;
    getLine("Hit [enter] to continue....   ");
}

/**
 * Function: main
 * --------------
 * Provides the entry point of the entire program.
 */


static void createGrid(Grid<int>& board){
    for (int i=0; i<board.numRows(); i++){
        for (int j=0; j < board.numCols(); j++){
           if (isOccupied()){
                board[i][j] = initAge(kMaxAge);
           }
        }
    }
}

static bool isOccupied(){
    return randomBool();
}


static int initAge(int kMaxAge){
    return randomInteger(1, kMaxAge+1);
}

static void randomSize(int minrow, int maxrow, int mincol, int maxcol, int& rowsize, int& colsize){
    rowsize = randomInteger(minrow, maxrow+1);
    colsize = randomInteger(mincol, maxcol+1);
}





int main(){
    LifeDisplay display;
    display.setTitle("Game of Life");
    welcome();
    int rowsize, colsize;
    randomSize(MINROW, MAXROW, MINCOL, MAXCOL, rowsize, colsize);
    Grid<int> grid(rowsize, colsize); //init grid with given rowsize and colsize
    createGrid(grid); // init colony into a grid with random ages across on the grid
    return 0;
}
