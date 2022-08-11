#include <iostream>
#include <cmath>
#include "vector.h"
#include "console.h"
#include "grid.h"
using namespace std;

int main() {
    Vector<int> nums = {42, 17, -6, 0, 28};
    cout << nums << endl;
    Vector<int> v;
    v.add(12);
    v.add(11);
    v.add(10);
    v.insert(1,5);
    cout << v << endl;
    Grid<int> matrix(3, 4);
    int count = 0;
    for (int r = 0; r < matrix.numRows(); r++) {
        for (int c = 0; c < matrix.numCols(); c++) {
            count++;
            matrix[r][c] = count;
        }
    }
    count = 0;
    cout << matrix << endl;
    for (int c = 0; c < matrix.numCols(); c++) {
        for (int r = 0; r < matrix.numRows(); r++) {
            count++;
            matrix[r][c] = count;
        }
    }
    cout << matrix << endl;
    return 0;
}
