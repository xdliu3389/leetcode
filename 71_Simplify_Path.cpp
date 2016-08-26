/*
 *  Learn some useful things about stringstream
 *
 *  Problem:
 *      Given an absolute path for a file (Unix-style), simplify it.
 *      For example,
 *      path = "/home/", => "/home"
 *      path = "/a/./b/../../c/", => "/c"
 *
 *  Solution:
 *      There are 2 steps:
 *      1. Reduce the successive / to one /
 *      2. Simplify. We can use stack. When we meet . continue, .. pop, else push_back
 *
 *      Actually we can reduce the 2 steps to 1 step : Split the string with /, and do the simplify operation again.
 *      As we know, there is no split() function in string, but we can use stringstream and getline to do this.
 *      Let's take a look at how we make it.
 * */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string res, tmp;
        vector<string> tmpRes;
        stringstream ss(path);

        // The 3d parameter of getline is delimiter (type is char). And stringstream ss(path) means convert string path to a stringstream which can be set the 1st parameter of getline.
        // getline will read ss by the delimiter untile end.
        while(getline(ss, tmp, '/')) {
            if(tmp == "" || tmp == ".") continue;
            else if(tmp == ".." && !tmpRes.empty()) tmpRes.pop_back();
            else if(tmp != "..") tmpRes.push_back(tmp);            
        }

        // This is the iterator only in C++11. I like this kind of elegant style iteration
        // You must compile this code in : g++ *.cpp -std=c++11.
        for(auto str : tmpRes)
            res += "/"+str;
        
        return res.empty() ? "/" : res;

    }
};

int main()
{
    Solution s;
    string path;
    getline(cin, path);
    cout << s.simplifyPath(path) << endl;

    return 0;
}
