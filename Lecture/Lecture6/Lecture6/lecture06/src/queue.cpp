/*
 * CS 106B/X, Ashley Taylor
 * This program demonstrates using the Stack collection class.
 */

#include <iostream>
#include "console.h"
#include "queue.h"
#include "stack.h"
using namespace std;

void repeat(Queue<int> &queue);
void mirror(Queue<string> &queue);

int main() {
    Queue<int> queue = {1, 2, 3};
    cout << "Before repeat: " << queue << endl;
    repeat(queue);
    cout << "After repeat: " << queue << endl;

    Queue<string> q = {"a", "b", "c"};
    cout << "Before mirror: " << q << endl;
    mirror(q);
    cout << "After mirror: " << q << endl;
    return 0;
}

/*
 * Accepts a queue of integers. Replaces every element with two copies of
 * that element.
 */
void repeat(Queue<int> &queue) {
    //TODO
    int size = queue.size();
    for (int i = 0; i < size; ++i) {
        int k = queue.dequeue();
        queue.enqueue(k);
        queue.enqueue(k);
    }
}

/*
 * Accepts a queue of strings. Appends the queue's contents to itself in
 * reverse order.
 */
void mirror(Queue<string> &queue) {
    //TODO
    Stack<string> s;
    Queue<string> temp  = queue;
    while (!temp.isEmpty()){
        s.push(temp.dequeue());
    }
    while (!s.isEmpty()){
        queue.enqueue(s.pop());
    }
}
