#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights)
    {
        bool flag=true;
        int len = heights.size();
        int currentHeight=1, max=0, curLen=0, biggerNum=0;
        vector<int> ans;
        while(flag) {
            flag = false;
            curLen=0; max=0; biggerNum=0
            for(int i=0; i<len; i++) {
                if(heights[i] >= currentHeight) {
                    biggerNum++;
                    curLen++;
                    flag = true;
                }
                if(heights[i] < currentHeight) {
                    max = (max>curLen)?max:curLen;
                    curLen = 0;
                }
            }
            max = (max>curLen)?max:curLen;
            ans.push_back(currentHeight*max);
            currentHeight++;
        }
        max = ans[0];
        for(int i=1; i<ans.size(); i++) {
            if(ans[i] > max)
                max = ans[i];
        }
        return max;
    }
};

int main()
{
    Solution s;
    vector<int> h;
    h.push_back(2);
    h.push_back(2);
    h.push_back(1);
    cout << s.largestRectangleArea(h) << endl;
    return 0;
}
