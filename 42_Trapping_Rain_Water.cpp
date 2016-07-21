/*
 *  Good problem. Key-word: Left-Right Pointer
 *
 *
	Problem:
	Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap afte    r raining.
	For example, 
	Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
	See 42.png

	Solution1:
    We set two pointer l and r, set them to 1 and len-2 at first. We set lm and rm as the max value of left to index l and right to index r.So we set them height[0] and height[len-1] at first.
    Than we have follow moving rule:
    1.If height[l-1]<height[r+1], than we can confirm the container of index l, because the container is:lm-height[l](assume lm is bigger than height[l])
    2.If height[l-1]<height[r+1], than we can confirm the container of index r,.....
    3.If 1, than we compute the container and sum it to the result, and move l to right(l++);
    4.If 2, than we compute the container and sum it to the result, and move r to left(r--);
    5.Loop 1,2,3,4 until l==r.


	Solution2:
	Let's take look at ith node. And we can see that, the trp of ith node is min(maxLeftNodesHeight, maxRightNodesHeight)-height, of course the
	precondition is min() is higher than height. So we can loop the array twice to get the maxLeftNodesHeight array and the maxRight one.
	And than we loop from left to right to sum the trap.
	The shortcoming here is we need two array, the size if n. So if the height is so long, than we may meet memory problem. And we can find that
	what we need is only one array to store the less one between l[i-1] and r[i+1], as you can see from the code. But the space is still O(n).
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
public:
    int trap(vector<int>& height) {
		int len = height.size();
		if(len <= 2)
			return 0;
		if(3 == len) {
			if(height[0]>height[1] && height[2]>height[1])
				return min(height[0], height[2])-height[1];
		}
		int l, r, lm, rm, res;
        lm = height[0];
        rm = height[len-1];
		l=1; r=len-2; res=0;
		while(l <= r) {
			if(height[l-1] < height[r+1]) {
				if(lm > height[l])
					res = res + lm - height[l];
                else
                    lm = height[l];
				l++;	
			} else {
				if(rm > height[r])
					res = res + rm - height[r];
                else
                    rm = height[r];
				r--;
			}
		}		
		return res;
    }
};

void printV(int m[], int len)
{
	for(int i=0; i<len; i++)
		cout << m[i] << " ";
	cout << endl;
}

class Solution2 {
public:
    int trap(vector<int>& height) {
		int len = height.size();
		int res = 0;
		if(len <= 0)
			return 0;

		//l[i] and r[i] are maxHeight in left side and right side when at index i
		int *l = new int[len];
		int *r = new int[len];
		l[0] = height[0];
		r[len-1] = height[len-1];

		//Loop twice get the l and r array	
		for(int i=1; i<len; i++)
			l[i] = height[i]>l[i-1]?height[i]:l[i-1];
		for(int i=len-2; i>=0; i--)
			r[i] = height[i]>r[i+1]?height[i]:r[i+1];
		
		//Sum every trap based on l and r.
		for(int i=1; i<len-1; i++) {
			if(min(l[i-1], r[i+1]) > height[i])
				res = res + min(l[i-1], r[i+1]) - height[i];
		}
		return res;
    }
};

int main()
{
	vector<int> h;
	h.push_back(0);
	h.push_back(1);
	h.push_back(0);
	h.push_back(2);
	h.push_back(1);
	h.push_back(0);
	h.push_back(1);
	h.push_back(3);
	h.push_back(2);
	h.push_back(1);
	h.push_back(2);
	h.push_back(1);

	Solution1 s;
	cout << s.trap(h) << endl;
}
