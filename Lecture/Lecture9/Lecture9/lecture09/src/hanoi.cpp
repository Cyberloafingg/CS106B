/*
 * CS 106B/X, Marty Stepp
 * This file tests the recursive hanoi function.
 */

#include <iostream>
#include "console.h"
#include "recursion.h"
#include "strlib.h"
#include "hanoigui.h"

using namespace std;

// function prototype declarations
void moveDiscs(int numDiscs, int startPeg, int endPeg);

int hanoi_main() {
    int numDiscs = 6;
    HanoiGui::initialize(numDiscs);
    HanoiGui::setWaitForClick(true);
    moveDiscs(numDiscs, 0, 2);
    return 0;
}

// Moves the given number of discs from the given starting peg number (from 0-2)
// to the given ending peg number (from 0-2), recursively.
// Uses the functions of the HanoiGui to draw the work.
void moveDiscs(int numDiscs, int startPeg, int endPeg) {

}






