/*
	Good problem, need pay attention!

	Problem:
		Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that        the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the contai        ner contains the most water.

	Solution1:
		It's easy to write code to loop twice and calculate the result, but it's time-consuming.

	Solution2:
		Choose l and r which l=0 and r=len-1;
		Than we move l and r like this:
		1	If(height[l] < height[r])
		2		l++;
		3	else
		4		r--;
		On 1, if the height[l] < height[r], than the lines left to r are equal or smaller than this [l, r] container, we can only raise the area
		by moving the l to right.
		On 3, if the height[l] > height[r], than the line right to l are ....., so we need move r to left.
		And while l==r, the res is just what we want.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
		int l, r;
		int res = 0;
		l = 0;
		r= height.size() - 1;
		while(l < r) {
			//Find the max between current area and before res.
			res = max(res, (r-l)*min(height[l], height[r]));
			//Move l right when height[l] < height[r]
			if(height[l] < height[r])
				l++;
			//Move r left when height[l] > height[r]
			else
				r--;
		} 	
		return res;
	}
};

int main()
{

}
