/*
 * CS 106B/X, Marty Stepp and Julie Zelenski
 * This file contains several recursive function examples.
 * A recursive function is one that calls itself.
 * A recursive call often handles a small part of the overall problem,
 * leaving the rest to be handled by other self-calls.
 */

#include <cctype>
#include <fstream>
#include <iostream>
#include "console.h"
#include "filelib.h"
#include "recursion.h"
#include "strlib.h"
using namespace std;

// function prototype declarations
void reverseLines(ifstream& input);
void crawl(string filepath, string indent = "");
int evenDigits(int n);

// If you can't solve reverseLines, here, you can cheat!
void cheatLOL(ifstream& input);

void test_reverseLines(const string& filename);

int main() {
    
     // test the reverseLines function
        cout << "reverseLines tests: " << endl;
        test_reverseLines("poem.txt");
        cout << endl;
        test_reverseLines("empty.txt");
        cout << endl;
        test_reverseLines("gettysburg.txt");
        cout << endl;

        // test the crawl function
           cout << "crawl test: " << endl;
           crawl("~/Downloads/lecture09");

//    // test the evenDigits function
//    cout << "evenDigits tests: " << endl;
//    cout << "evenDigits(8342116) " << evenDigits(8342116) << " should be " << 8426 << endl;
//    cout << "evenDigits(40109) " << evenDigits(40109) << " should be " << 400 << endl;
//    cout << "evenDigits(8) " << evenDigits(8) << " should be " << 8 << endl;
//    cout << "evenDigits(-163505) " << evenDigits(-163505) << " should be " << -60 << endl;
//    cout << "evenDigits(35179) " << evenDigits(35179) << " should be " << 0 << endl;

    return 0;
}

/*
 * Prints to the console the lines from the given input file, in the opposite
 * order that they appear in the file.
 * If the file contains no text, this function produces no output.
 *
 * Example file poem.txt:   =>   output:
 *   1 roses are red               are belong to you
 * > 2 violets are blue            all my base
 *   3 all my base                 violets are blue
 *   4 are belong to you           roses are red
 */
void reverseLines(ifstream& input) {
    // TODO
    string line;
    if(getline(input,line)){
        reverseLines(input);
        cout << line << endl;
    }
}



/*
 * Prints information about this file,
 * and (if it is a directory) any files inside it.
 */
void crawl(string filepath, string indent) {
    // TODO

}

/*
 * Accepts an integer and returns a new number containing
 * only the even digits, in the same order.
 * If there are no even digits, return 0.
 */
int evenDigits(int n) {
   // TODO
    return 0;
}




// =================== testing code below =================== //

// tests the reverseLines function
void test_reverseLines(const string& filename) {
    ifstream input;
    input.open(filename);
    if (input.fail()) {
        cerr << "file not found: " << filename << endl;
        return;
    }
    cout << "reverseLines(\"" << filename << "\") = " << endl;
    reverseLines(input);
    input.close();
}

// A pre-written solution to reverseLines.
void cheatLOL(ifstream& input) {
    reverseLines(input);   // LOLOL I just call your function
}
