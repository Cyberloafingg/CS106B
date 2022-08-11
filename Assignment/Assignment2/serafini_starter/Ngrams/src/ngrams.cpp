// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "hashmap.h"
#include "set.h"
#include "random.h"
#include "queue.h"
#include <locale>
using namespace std;

void printWelcome();
void inputFileAndN(ifstream &fin, int &N);
void buildMap(HashMap<Queue<string>, Vector<string>> &map, int &N, ifstream &fin);
void generate(ifstream &fin, int &N);

int main() {
    // TODO: Finish the program!
    printWelcome();
    ifstream fin;
    int N;
    inputFileAndN(fin, N);
    generate(fin, N);

    cout << "Exiting." << endl;
    return 0;
}

void printWelcome(){
    cout << "Welcome to CS 106B Random Writer ('N-Grams')." << endl;
    cout << "This program makes random text based on a document." << endl;
    cout << "Give me an input file and an 'N' value for groups" << endl;
    cout <<  "of words, and I'll create random text for you." << endl;
}

void inputFileAndN(ifstream &fin, int &N){
    string fileName;
    while (true){
        cout << "Input file name? ";
        cin >> fileName;
        fin.open(fileName);
        if (!fin.fail())
            break;
        cout << "Unable to open that file.  Try again." << endl;
    }
    cout << "Value of N? ";
    cin >> N;
    while (!cin || cin.peek()!= '\n' || N < 2){
        cin.clear();
        cin.ignore(200, '\n');
        if (N < 2 && N != 0){
            cout << "N must be 2 or greater." << endl;
        }else{
            cout << "Illegal integer format. Try again." << endl;
        }
        cout << "Value of N? ";
        cin >> N;
    }
    cout << endl;
}

void generate(ifstream &fin, int &N){
    /*----------build map---------*/
    HashMap<Queue<string>, Vector<string>> map;
    buildMap(map, N, fin);
    //循环
    bool exit = false;
    while (true) {
        /*---------select lenth-------*/
        int lenth;
        cout << "# of random words to generate (0 to quit)? ";
        cin >> lenth;
        while (!cin || cin.peek()!= '\n' || lenth < 4){
            cin.clear();
            cin.ignore(200, '\n');
            if (lenth < 4 && lenth != 0){
                cout << "Must be at least 4 words." << endl;
            }else{
                cout << "Illegal integer format. Try again." << endl;
                exit = true;
                break;
            }
            cout << "# of random words to generate (0 to quit)? ";
            cin >> lenth;
        }
        if(exit)
            break;
        /* --------Generate sentence-------*/
        string line = "... ";
        // random select origin
        Queue<string> temp =randomKey(map);

        for (int i = 0; i < lenth; i++) {
            /*
             * 1.首先根据tempWindow当作key，去找后面的value
             * 2. 把value当作按照map的形式进行存储，map<string,int>
             * 3. 按照加权，那就是直接random去找一个string
             * 4. 取出这个string，队列出队值line += temp.dequeue();队列入队这个string
             */
            Vector<string> candVec = map.get(temp);
            int index = randomInteger(0,candVec.size()-1);
            string nextString = candVec[index];
            line += temp.dequeue();
            line += " ";
            temp.enqueue(nextString);
        }
        line += "...";
        cout << line << endl;
        cout << endl;
    }

}

void buildMap(HashMap<Queue<string>, Vector<string>> &map, int &N, ifstream &fin){
    string word;
    Queue<string> windows, wrapWindows;
    Vector<string> v1, v2;
    // 如果传入N-gram，窗口大小应该是N-1
    for (int i = 0; i < N-1; ++i) {
        fin >> word;
        windows.enqueue(word);
    }
    wrapWindows = windows;
    while(fin >> word){
        v1.add(word);
        if (map.containsKey(windows)) {
            map[windows].add(v1.get(v1.size()-1));
        }else{
            map.add(windows,v1);
        }
        windows.dequeue();
        windows.enqueue(v1.get(v1.size()-1));
        v1.clear();
    }
    while(!wrapWindows.isEmpty()){
        v1.add(wrapWindows.dequeue());
        if (map.containsKey(windows)) {
            map[windows].add(v1.get(v1.size()-1));
        }else{
            map.add(windows,v1);
        }
        windows.dequeue();
        windows.enqueue(v1.get(v1.size()-1));
        v1.clear();
    }
}


