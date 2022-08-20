/*
 * CS 106B/X, Marty Stepp
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
#include "map.h"
#include "queue.h"
#include "recursion.h"
#include "strlib.h"
using namespace std;

// function prototype declarations
int fib(int n);
int evaluate(string expression);
Queue<string> tokenizeExpression(string expression);
void test_evaluate(string expression, int expected);


int fib_main() {
    //test the fib function
//    cout << "fib tests:" << endl;
//    cout << "fib(1): " << fib(1) << endl;
//    cout << "fib(2): " << fib(2) << endl;
//    cout << "fib(3): " << fib(3) << endl;
//    cout << "fib(4): " << fib(4) << endl;
//    cout << "fib(5): " << fib(5) << endl;
//    cout << "fib(6): " << fib(6) << endl;
//    cout << "fib(7): " << fib(7) << endl;
//    cout << "fib(8): " << fib(8) << endl;
//    cout << "fib(9): " << fib(9) << endl;


    //    // test the evaluate function
    //    cout << "evaluate tests:" << endl;
    //    test_evaluate("(1+(2*4))", 9);
    //    test_evaluate("((1+3)*(2*(4+1)))", 40);
    //    test_evaluate("((1+1)*(12*(3+3)))", 144);
    //    test_evaluate("((1+3)+((1+2)*5))", 19);
    //    test_evaluate("((138+(29*2))+(((44+55)+17)*198))", 23164);

    return 0;
}

int fib(int n) {
    // TODO
    return 0;
}

/*
 * Evaluates mathematical expressions that use addition and multiplication,
 * expressed as a queue of tokens.
 * The queue representation is easier to process than a bare string, so we write
 * our recursive code this way.
 */
int evaluate(Queue<string>& tokens) {

    // { 42 }
    // (, 1, +, (, 2, *, 4, ), )
    if (stringIsInteger(tokens.peek())) {
        // base case seems to be just a number
        string num = tokens.dequeue();   // "7"
        return stringToInteger(num);     // 7
    } else {
        // recursive case seems to be, (A op B)
        // {"(", "7", "+", "4", ")"}
        tokens.dequeue();                  // "("
        int left = evaluate(tokens);
        string op = tokens.dequeue();      // "+"
        int right = evaluate(tokens);
        tokens.dequeue();                  // ")"
        if (op == "+") {
            return left + right;
        } else {  // "*"
            return left * right;
        }
    }
}

/*
 * Evaluates mathematical expressions that use addition and multiplication.
 * Assumes:
 * - expression is "fully parenthesized"
 * - expression format is valid
 * - all numbers in expression are non-negative integers
 *
 * Examples:
 * "7"                  => 7
 * "(2+2)"              => 4
 * "(1+(2*4))"          => 9
 * "((1+3)+((1+2)*5))"  => 19
 * "((138+(29*2))+(((44+55)+17)*198))" => 23164
 */
int evaluate(string exp) {
    Queue<string> tokens = tokenizeExpression(exp);
    return evaluate(tokens);
}



// =================== testing code below =================== //

// Tests whether or not the given expression evaluates to the given input
// and tests the result.
void test_evaluate(string expression, int expected) {
    int result = evaluate(expression);
    cout << "evaluate(" << expression << ") returned " <<  result << " ";
    cout << (result == expected ? "PASS" : "FAIL") << endl;
}

// Converts a parenthesized expression string into a queue of its tokens.
// For example, "(12+(345*67))" => {"(", "12", "+", "(", "345", "*", "67", ")", ")"}
Queue<string> tokenizeExpression(string expression) {
    Queue<string> tokens;
    const string operators = "()+-*/";
    string num = "";
    while (!expression.empty()) {
        char ch = expression[0];
        expression.erase(0, 1);
        if (operators.find(ch) != string::npos) {
            if (!num.empty()) {
                tokens.enqueue(num);
                num = "";
            }
            tokens.enqueue(charToString(ch));
        } else {
            // digit
            num += ch;
        }
    }

    // possible number left at end
    if (!num.empty()) {
        tokens.enqueue(num);
    }

    return tokens;
}
