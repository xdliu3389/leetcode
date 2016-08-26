/*
 * Good one!
 *
 * Problem: Implement int sqrt(int x).
 *          Compute and return the square root of x.
 *
 * Solution: Newton solver.
 *          x(n+1) = (x(n) + a/x(n)) / 2;
 *          This is the formula. And choose a value as x0, and iterate solve.
 *
 * */

#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int r = x;
        while(r*r != x) {
            r = (r + x/r) / 2;
        }
        return r;
    }                
};

int main()
{
    Solution s;
    while(true) {
        int x;
        cin >> x;
        cout << s.mySqrt(x) << endl;
    }

    return 0;
}
