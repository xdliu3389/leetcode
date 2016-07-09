/*
	Problem:
		Suppose a sorted array is rotated at some pivot unknown to you beforehand.
		(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
		You are given a target value to search. If found in the array return its index, otherwise return -1.
		You may assume no duplicate exists in the array.
	
	How:
		Solution1:
			Build a hash map of all the element first. And then check if the target is hashed already.
			Time:O(n) Space:larger than O(n)	
		Solution2:
			Based on the solution of Binaray Search.
			We first find the smallest element in the vector based on Binary Search, than we do the Binary Search in
			left block or the right block based on the comparison between the smallest number and the target.
			TIme:O(lg n) Space:O(1)
	
	Comiple command:
		g++ fileName --std=c++11
		unordered_map is newly employeed in c++ 11. So you should add --std=c+11 to guarantee g++ support this library
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <unordered_map>
#define MAGICNUMBER 10
using namespace std;

int g[] = {68,69,70,71,72,74,75,77,82,84,90,91,92,93,94,102,104,105,106,107,109,110,111,112,113,114,121,122,123,124,125,127,129,131,132,137,139,142,143,149,151,154,162,166,167,170,172,176,177,179,184,185,187,188,189,193,195,198,202,204,205,206,208,210,211,212,215,221,222,227,230,231,232,235,236,238,239,240,246,247,249,250,253,255,256,261,263,266,267,270,271,273,274,275,276,277,278,280,281,282,285,286,287,289,295,297,299,0,4,7,10,12,15,18,19,24,27,29,30,32,34,35,36,37,41,42,43,44,45,48,52,53,55,65,67};

class Solution1 {
public:
    int search(vector<int>& nums, int target) {
		unordered_map<int, int> tmpMap;
		int len = nums.size();
		for(int i=0; i<len; i++) {
			tmpMap[nums[i]] = i;
		}
		if(tmpMap.count(target) == 0)
			return -1;
		else
			return tmpMap[target];
    }
};

class Solution2 {
public:
    int search(vector<int>& nums, int target) {
		int lo=0, mid, hi=nums.size()-1, len=nums.size();
		//If the len is less than MAGICNUMBER. Search the vector direcly will be easy and high efficiency
		if(len <= MAGICNUMBER) {
			for(int i=0; i<len; i++)
				if(target == nums[i])
					return i;
			return -1;
		}

		//After the loop, index of the smallest number is lo==hi
		while(lo < hi) {
			mid = (lo + hi) / 2;
			if(nums[mid] > nums[hi]) lo = mid+1;
			else hi = mid;
		}
		mid = lo;


		if(target < nums[mid])
			return -1;
		if(nums[mid]<=target && nums[len-1]>=target) {
			lo = mid; 
			hi = nums.size()-1;	
		} else {
			lo = 0;
			hi = mid;
		}
		//Binary Search in left block or the right block depends on the up code
		while(lo < hi) {
			mid = (lo + hi) / 2;
			if(nums[mid] == target)
				return mid;
			else if(nums[mid] < target)
				lo = mid + 1;
			else
				hi = mid;
		}
		return -1;
	}
};

int main()
{
	Solution1 ss;
	int count = sizeof(g)/sizeof(g[0]);
	vector<int> nums(g, g+count);
	cout << ss.search(nums, 166) << endl;
	return 0;
}
