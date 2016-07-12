/*
		Hard. Nice and frequent asked question. Need attention!!!

		Problem:
			Given a string s, partition s such that every substring of the partition is a palindrome.
			Return all possible palindrome partitioning of s.
			For example, given s = "aab",
			Return
			[
				["aa","b"],
				["a","a","b"]
			]

		How to:
			Solve this problem by recursive.
			Take string s = "aab" for example.
			Check "a" first, then "aa", finally "aab".
			When checking "a", the rest string is "ab", use "ab" as input to make a recursive call.
			The end state:
				If the start == len, then it's the boundary.
			For detail, you can see 131.png in this directory.
			(One should read dfs() function carefully if he doesn't know what's going on of this algorithm)

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	//check string s is a palindrome
	bool isPal(string s, int b, int e) {
		e = e - 1;
		while(b < e) {
			if(s[b++] != s[e--])
				return false;
		}
		return true;
	}

	//recursive search
	//The left string can be a input and call dfs() recursively.
	void dfs(string s, int start, vector<vector<string> > &res, vector<string> &tmp) {
		int len = s.size();
		if(start == len) {
			res.push_back(tmp);
		}
		for(int i=start+1; i<=len; i++) {
			if(isPal(s, start, i)) {
				tmp.push_back(s.substr(start, i-start));
				dfs(s, i, res, tmp);
				tmp.pop_back();
			}
		}
	}	

	vector<vector<string> > partition(string s) {
		vector<vector<string> > res;
		vector<string> tmp;
		dfs(s, 0, res, tmp);
		return res;
	}
};

int main()
{
	Solution s;
	vector<vector<string> > res = s.partition("");
	for(int i=0; i<res.size(); i++) {
		for(int j=0; j<res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
