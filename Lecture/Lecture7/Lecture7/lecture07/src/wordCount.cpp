/* Ashley Taylor
 * CS106B
 * A program to count the number of times each word
 * occurs in a file.
 * Prompts the user for a file to open,
 * gets the word counts,
 * and prints out the number of appearances
 * for each user-entered word.
 */

#include <fstream>
#include <iostream>
#include "console.h"
#include "filelib.h"
#include "map.h"
#include "simpio.h"
using namespace std;

int count_main() {
    ifstream infile;
    promptUserForFile(infile, "File?");
    string word;
    while (infile >> word) {

    }
    infile.close();

    string userWord = getLine("Enter a word (or enter to quit): ");
    while (userWord != "") {

        userWord = getLine("Enter a word (or enter to quit): ");
    }
    return 0;
}
