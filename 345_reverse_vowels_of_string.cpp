/*
	Easy Problem!!!
	Problem:
		Write a function that takes a string as input and reverse only the vowels of a string.
		
		Example 1:
		Given s = "hello", return "holle".
		
		Example 2:
		Given s = "leetcode", return "leotcede".

	How to:
		Easy operation on string. Check if vowel and then swap is ok.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string vowels = "aeiouAEIOU";
    int vLen = vowels.size();
	//Check if vowel
    bool isVowel(char c) {
        for(int i=0; i<vLen; i++) {
            if(vowels[i] == c)
                return true;
        }
        return false;
    }

    string reverseVowels(string s) {
        int len = s.size();
        if(len <= 1)
            return s;
        int i=0, j=len-1;
        char c;
		//The swap begins when both s[i[ && s[j] is vowel. If not, i++ or j-- based on the s[i] and s[j]
        while(i < j) {
			while(i<j && !isVowel(s[i]))
                i++;
			while(i<j && !isVowel(s[j]))
                j--;
            c = s[i];
            s[i] = s[j];
            s[j] = c;
			i++; j--;
        }
        return s;
    }
};

int main()
{
	Solution s;
	cout << s.reverseVowels("leetcode") << endl;
	return 0;
}
