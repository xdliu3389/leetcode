/*
 *  Good problem about left and right pointer. Similiar problem:42 and 11.
 *
 *  Problem:
 *      Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
 *
 *      Solve it without division and in O(n).
 *
 *      For example, given [1,2,3,4], return [24,12,8,6].
 *
 *  
 *
 *  Solution:
 *      1:    {              1,         a[0],    a[0]*a[1],    a[0]*a[1]*a[2],  }
 *      2:    { a[1]*a[2]*a[3],    a[2]*a[3],         a[3],                 1,  }
 *      We can get 1 and 2 both in O(n) with a loop. In fact, it's also about left and right pointer.
 *      Than we multiply 1 and 2 element by element, than we get the result.
 *
 *
 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> p;
        if(len == 2) {
            p.push_back(nums[1]);
            p.push_back(nums[0]);
            return p;
        }
        //Generate 1
        int right = 1;
        for(int i=0; i<len; i++) {
            p.push_back(right);
            right = right * nums[i];
        }
        //Generate 2 and multiply
        right = 1;
        for(int i=len-1; i>=0; i--) {
            p[i] = p[i] * right;
            right = right * nums[i];
        }
        return p;
    }
};


int main()
{
    Solution s;
    vector<int> n;
    n.push_back(9);    
    n.push_back(0);    
    n.push_back(-2);   
    n = s.productExceptSelf(n);
    for(int i=0; i<n.size(); i++)
        cout << n[i] << " " << endl;
    return 0;
}
