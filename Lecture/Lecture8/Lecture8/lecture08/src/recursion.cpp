/*
 * CS 106B/X, Marty Stepp
 * This file contains several recursive function examples.
 * A recursive function is one that calls itself.
 * A recursive call often handles a small part of the overall problem,
 * leaving the rest to be handled by other self-calls.
 */

#include <iostream>
#include "console.h"
#include "strlib.h"

using namespace std;

int factorial(int n);
void printStars(int n);
int power(int base, int exp);
bool isPalindrome(string s);
void printBinary(int n);
int mystery(int n);
int mystery2(int n);

void test_power(int base, int exp);
void test_isPalindrome(string s);
void test_printBinary(int n);

int main() {


    cout << "isPalindrome:" << endl;

    test_isPalindrome("racecar");          // true
    test_isPalindrome("Step on NO pEts");  // true
    test_isPalindrome("X");                // true
    test_isPalindrome("Java");             // false
    test_isPalindrome("racecars");         // false
    test_isPalindrome("toy robot");        // false
    cout << endl;


//    cout << "pow:" << endl;
//    test_power(3, 4);    // 81
//    test_power(4, 3);    // 64
//    test_power(2, 10);   // 1024
//    test_power(5, 3);    // 125
//    test_power(0, 5);    // 0
//    test_power(5, 0);    // 1
//    test_power(1, 8);    // 1
//    test_power(1, 4);    // 1
//    test_power(-4, 0);   // 1
//    test_power(-4, 3);   // 1
//    test_power(5, -3);      // crash
//    cout << endl;
    
//    cout << "evenDigits:" << endl;
//    test_evenDigits(812410010);
//    test_evenDigits(-4105);
//    test_evenDigits(93917);

//    cout << "printBinary:" << endl;
//    test_printBinary(2);      // 10
//    test_printBinary(12);     // 1100
//    test_printBinary(42);     // 101010
//    test_printBinary(-500);   // -111110100
//    cout << endl;

    cout << "Complete." << endl;
    
    return 0;
}


// 5! = 5 * 4!
// factorial(3)
//    -> return 3 * factorial(2)
//                     -> return 2 * factorial(1)
//                                     return 1
int factorial(int n) {
    // TODO
    return 0;
}


/*
 * Returns true if the given string reads the same
 * forwards as backwards, case-insensitively.
 * Trivially true for empty or 1-letter strings.
 * Example: isPalindrome("racecar") returns true.
 */
bool isPalindrome(string s) {
    // TODO
    if(s.length() < 2){
        return true;
    }else{
        if(s[0] != s[s.length() - 1]){
            return false;
        }
        string middle = s.substr(1, s.length() - 2);
        return isPalindrome(middle);
    }
}


/*
 * A recursive function that prints a given number of stars.
 * Precondition: n > 0.
 */
void printStars(int n) {
    // TODO
}


/*
 * Returns the given integer base raised to the given exponent.
 * Example: power(3, 4) returns 3^4 = 3*3*3*3 = 81.
 * Assumes exp >= 0.
 */
int power(int base, int exp) {
    // TODO
    return 0;
}


/*
 * Prints the given integer's binary representation.
 * Example: printBinary(43) outputs 101011.
 */
void printBinary(int n) {
    // TODO
    cout << n << endl;
}


// =================== testing code below =================== //

// tests the power function
void test_power(int base, int exp) {
    cout << "power(" << base << ", " << exp << ") = " << power(base, exp) << endl;
}

// tests the isPalindrome function
void test_isPalindrome(string s) {
    cout << "isPalindrome(\"" << s << "\") = " << boolalpha << isPalindrome(s) << endl;
}

// tests the printBinary function
void test_printBinary(int n) {
    cout << "printBinary(" << n << ") = ";
    printBinary(n);
    cout << endl;
}

/*
 * A confusing 'mystery' function to use as an example of recursion tracing.
 */
int mystery(int n) {
    if (n < 10) {
        return n;
    } else {
        int a = n / 10;
        int b = n % 10;
        return mystery(a + b);
    }
}

/*
 * A confusing 'mystery' function to use as an example of recursion tracing.
 */
int mystery2(int n) {
    if (n < 10) {
        return (10 * n) + n;
    } else {
        int a = mystery2(n / 10);
        int b = mystery2(n % 10);
        return (100 * a) + b;
    }
}
