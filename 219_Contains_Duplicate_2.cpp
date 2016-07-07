/*
    Problem:
        Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.

    How:
        It's very tricky solving many boundaries when using two loops directly.
        Here we use map(set is also ok). It can achieve high time efficiency.  
*/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> nmap;
        for(int i=0; i<nums.size(); i++) {
            //If the nums[i] hasn't appeared before, than map nums[i] to i;
            if(nmap.count(nums[i]) == 0)
                nmap[nums[i]] = i;          
            //If the nums[i] has appeared before, and if the distance is smaller than k. Than return true directly.
            else if(i-nmap[nums[i]] <= k)
                return true;
            //If the nums[i] has appeard before, but the distance is bigger than k. Than map nums[i] to i and continue.
            else
                nmap[nums[i]] = i;
        }
        return false;
    }
};

int main ()
{
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    bool flag = s.containsNearbyDuplicate(nums, 1);
    cout << flag << endl;

    return 0;
}
