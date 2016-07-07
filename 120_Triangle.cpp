/*
Problem:
	Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
	For example, given the following triangle
	[
	     [2],
	    [3,4],
	   [6,5,7],
	  [4,1,8,3]
	]
	The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

How:
	It will be much more easier to caculate from bottom to top.
	And the ith element of array should be:
	min(triangle[row+1][i], triangle[row+1][i+1])+triangle[row][i]
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>> &triangle) {
		int row = triangle.size();
		vector<int> res = triangle.back();
		for(int i=row-2; i>=0; i--) {
			int col = triangle[i].size();
			for(int j=0; j<col; j++) {
				res[j] = min(res[j], res[j+1]) + triangle[i][j];
			}
		}
		return res[0];
	}
};
