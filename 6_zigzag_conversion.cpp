/*
		Easy.Basic math calculation

		Problem:
		The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
		P   A   H   N
		A P L S I I G
		Y   I   R
		And then read line by line: "PAHNAPLSIIGYIR"
		Write the code that will take a string and make this conversion given a number of rows:
		string convert(string text, int nRows);
		convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

		How:
		It's very easy to find the rule when we draw some test in the paper.
		And what we need to do after is do the normal loop traversal on the basis of math rule.

	
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
		int k = (numRows-1)*2;
		int len = s.size();
		string res = "";
		int tmpk = k, j;
		if(numRows < 1)
			return NULL;
		if(numRows==1 || len<=numRows)
			return s;
		//tmpk is the step in every row. The rule is that, tmpk is reduced by 2 with row adds.
		for(int i=0; i<numRows; i++) {
			j=i;
			tmpk = k - 2*i;
			while(j < len) {
				res += s[j];
				if(tmpk!=k && tmpk!=0) {
					if(j+tmpk < len)
						res += s[j+tmpk];
				}
				j += k;
			}
		}
		return res;
    }
};

int main()
{
	Solution s;
	string test = "ABCDEFGHIJKLMN";
	cout << s.convert(test, 3) << endl;
	return 0;
}
