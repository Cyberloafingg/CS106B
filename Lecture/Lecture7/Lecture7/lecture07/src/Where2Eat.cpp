/* Ashley Taylor
 * CS106B
 *
 * Where2Eat takes a file like this:
 * guest
 * restaurant
 * restaurant
 *
 * guest
 * ...
 *
 * And then asks for a group of people to eat together
 * and prints all the acceptable restaurants
 */

#include <fstream>
#include <iostream>
#include "console.h"
#include "filelib.h"
#include "map.h"
#include "set.h"
#include "simpio.h"
#include "stack.h"
#include "queue.h"
using namespace std;

int main() {
    ifstream file;
    file.open("restaurants.txt");
    string myFriend;
    Map<string, Set<string> > map;
    while (getline(file, myFriend)) {
        string restaurant;
        while (getline(file, restaurant) && restaurant != "") {
            map[myFriend] += restaurant;
        }
    }

    string guest = getLine("Enter a guest: ");
    while (guest != "") {
        while (guest != "") {

            guest = getLine("Enter a guest: ");
        }
        cout << "Here are the acceptable restaurants:" << endl;

    }
    return 0;
}
