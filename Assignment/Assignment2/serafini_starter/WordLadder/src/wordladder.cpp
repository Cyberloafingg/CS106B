// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "lexicon.h"
#include "queue.h"
#include <unordered_set>

using namespace std;

void printWelcome();
void selectFile(ifstream &fin, string &filename, Lexicon &dict);
void inputWord(string &wordbeg, string &wordend, Lexicon &dict);
void findLadder(string &wordstr, string &wordend, Lexicon &dict);

int main() {
    // TODO: Finish the program!
    /* -------- welcome -------- */
    printWelcome();
    /* ------- build dict ------- */
    string filename, wordstr, wordend;
    ifstream fin;
    Lexicon dict;
    selectFile(fin, filename, dict);
    /* ------ input and find------*/
    inputWord(wordstr, wordend, dict);
    cout << "Have a nice day." << endl;
    return 0;
}

void printWelcome(){
    cout << "Welcome to CS 106B Word Ladder.\n\
Please give me two English words, and I will change the\n\
first into the second by changing one letter at a time.\n\n";
}

void selectFile(ifstream &fin, string &filename, Lexicon &dict){
    while(true){
        cout << "Dictionary file name? ";
        getline(cin, filename);
        fin.open(filename);
        if (!fin.fail()) break;
        cout << "Unable to open that file.  Try again." << endl;
    }
    dict.addWordsFromFile(fin);
}
void inputWord(string &wordstr, string &wordend, Lexicon &dict){
    while (true){
        cin.clear();
        cin.sync();
        cout << endl;
        cout << "Word #1 (or Enter to quit):";
        getline(cin, wordstr);
         if(wordstr == "") break;
        cout << "Word #2 (or Enter to quit):";
        getline(cin, wordend);
        if(wordstr == "" || wordend == "") break;
        wordstr = toLowerCase(wordstr);
        wordend = toLowerCase(wordend);
        if (wordstr.length() != wordend.length()){
            cout << "The two words must be the same length." << endl;
            inputWord(wordstr, wordend, dict);
            break;
        }else if (!dict.contains(wordstr) || !dict.contains(wordend)){
            cout << "The two words must be found in the dictionary." << endl;
            inputWord(wordstr, wordend, dict);
            break;
        }else if (wordstr == wordend){
            cout << "The two words must be different." << endl;
            inputWord(wordstr, wordend, dict);
            break;
        }else{
            findLadder(wordstr, wordend, dict);
            inputWord(wordstr, wordend, dict);
            break;
        }
    }
}

void findLadder(string &wordstr, string &wordend, Lexicon &dict){
    //Create an empty queue of stacks.
    Queue< Stack<string>> ladders;
    //Create/add a stack containing {w1} to the queue.
    Stack<string> ladder;
    Lexicon usedword;
    /* --- init --- */
    ladder.push(wordstr);
    ladders.enqueue(ladder);
    usedword.add(wordstr);
    bool flag = false;
    //While the queue is not empty:
    while (!ladders.isEmpty()) {
        //Dequeue the partial-ladder stack from the front of the queue.
        Stack<string> tempLadder = ladders.dequeue();
        //For each valid English word that is a "neighbor" (differs by 1 letter) of the word on top of the stack:

        string tempWord = tempLadder.peek();
        wordstr = tempWord;
        if (wordstr == wordend){
            flag = true;
            cout << "A ladder from " << wordstr<< " back to " << wordend <<":" << endl;
            while (!tempLadder.isEmpty()){
                cout << tempLadder.pop() << " ";
            }
            cout << endl;
            break;
        }
        /*--- 寻找与栈顶word的邻居单词---*/
        int size = tempWord.length();
        for (int i = 0; i < size; ++i){
            for (char latter = 'a'; latter <= 'z'; latter++){
                string checkWord = tempWord;
                checkWord[i] = latter;
                if (dict.contains(checkWord) && !usedword.contains(checkWord)){
                    Stack<string> nextLadder = tempLadder;
                    usedword.add(checkWord);
                    nextLadder.push(checkWord);
                    ladders.enqueue(nextLadder);
                }
            }
        }
    }
    //没有找到的情况
    if(!flag)
        cout << "No word ladder found from \"" << wordend << "\" back to \"" << wordstr << "\"." << endl;
}

