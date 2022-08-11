/*
 * CS 106B/X, Ashley Taylor
 * This program demonstrates using the Stack collection class.
 */

#include <iostream>
#include "console.h"
#include "stack.h"
using namespace std;

const char SPACE = ' '; // a constant to denote our space delimiter

// function prototype declarations
void printSentenceReverse(const string &sentence);

int main() {
    string sentence1 = "Hello my name is Inigo Montoya";
    cout << sentence1 << endl;
    printSentenceReverse(sentence1);

    string sentence2 = "inconceivable";
    cout << sentence2 << endl;
    printSentenceReverse(sentence2);
    return 0;
}

/*
 * Accepts a string of letters and spaces, and, using the whitespace as a delimiter
 * for each word, prints the sentence in reverse order.
 */
void printSentenceReverse(const string &sentence) {
    //TODO
    Stack<string> wordstack;
    string word = "";
    for (char c : sentence){
        if(c != SPACE){
            word += c;
        }else{
            wordstack.push(word);
            word ="";
        }
    }
    if (word != "")
        wordstack.push(word);
    while(!wordstack.isEmpty()){
        cout << wordstack.pop() << " ";
    }
    cout << endl;

}
