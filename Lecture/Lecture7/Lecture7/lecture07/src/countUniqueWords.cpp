/* Ashley Taylor
 * CS106B
 * A program to count the number of unique words in a file.
 * Prompts the user for a file to open,
 * counts the number of unique words,
 * and prints out the number of unique words.
 */

#include <fstream>
#include <iostream>
#include "console.h"
#include "filelib.h"
#include "gwindow.h" // for GWindow
#include "lexicon.h"
#include "set.h"
#include "timer.h" // for timing
#include "vector.h"  // for Vector
using namespace std;

bool contains(const Vector<string> & uniqueWords, const string &target);

int unique_main() {
    Vector<string> uniqueWords;
    Timer timer;
    ifstream infile;
    string filename = promptUserForFile(infile, "File?");
    timer.start();

    string word;

    while(infile >> word) {
        if (!contains(uniqueWords, word)) {
            uniqueWords.add(word);
        }
    }

    infile.close();


    timer.stop();
    cout << "There are " << uniqueWords.size() << " unique words in " << filename << endl;
    cout << "It took " << timer.elapsed() << " milliseconds to run this program." << endl;

    return 0;
}

bool contains(const Vector<string> &uniqueWords, const string & target) {
    for (string word : uniqueWords) {
        if (word == target) {
            return true;
        }
    }
    return false;
}
