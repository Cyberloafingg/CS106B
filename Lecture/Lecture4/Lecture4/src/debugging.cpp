/*
 * CS 106B/X, Ashley Taylor
 * This program gives practice for effective debugging.
 * It should rotate the image 90 degrees counter-clockwise.
 */

#include <iostream>
#include <fstream>
#include "console.h"
#include "filelib.h"
#include "grid.h"
#include "strlib.h"
using namespace std;

bool isVowel(char ch) {
    return ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' ||
            ch == 'i' || ch =='I' || ch == 'o' || ch == 'O' ||
            ch == 'u' || ch == 'U';
}

void countStatistics() {

}

void avgScores(string filename = "scores.txt") {
    ifstream inf;
    inf.open(filename);
    string line;
    double score = 0;
    while(getline(inf, line)){
        Vector<string> str = stringSplit(line, ":");
        cout << line << endl;
        score += stringToInteger(str[1]);
        cout << score << endl;
    }




}

int main() {
    ifstream inf;
    inf.open("redFern.txt");
    char ch;
    // read char by char
    while(inf.get(ch)){
        cout << ch;
    }
    inf.close();
    // read line by line
    string line;
    inf.open("redFern.txt");
    while(getline(inf, line)){
        cout << line << endl;
    }

    countStatistics();
    avgScores();
    return 0;
}
