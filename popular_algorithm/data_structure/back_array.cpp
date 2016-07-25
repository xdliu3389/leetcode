/*
 *  Problem:
 *      Find the longest same substr in the one string or two strings.
 *
 *  Solution:
 *      Using back_array to store all the substr, sort them, and compare length.
 *      For example:
 *      1. string s = "banana"
 *      2. Then we have back_string:
 *         a[0] = banana
 *         a[1] = anana
 *         a[2] = nana
 *         a[3] = ana
 *         a[4] = na
 *         a[5] = a
 *      3. Sort the array
 *         a[0] = a
 *         a[1] = ana
 *         a[2] = anana
 *         a[3] = banana
 *         a[4] = na
 *         a[5] = nana
 *      4. Loop the array and we can get the longest same substr is 3.
 *
 *
 * */
#include <iostream>
#include <string>

using namespace std;

class QSortString{
private:
    string *backStr;
    int bslen;

public:
    /**Quick sort for string array**/
    int assignArr(string s[], int l, int r) {
        string tmp = s[l];
        while(l < r) {
            while(l<r && s[r]>tmp)
                r--;
            s[l++] = s[r];
            while(l<r && s[l]<tmp)
                l++;
            s[r--] = s[l];
        }
        s[l] = tmp;
        return l;
    }

    void qsort(string s[], int l, int r) {
        if(l < r) {
            int mid = assignArr(s, l, r);
            qsort(s, l, mid-1);
            qsort(s, mid+1, r);
        }
    }
    /**Quick sort for string array**/

    int complen(string s1, string s2)
    {
        int len = 0;
        while(s1[len]!='\0' && s2[len]!='\0' && s1[len]==s2[len])
            len++;
        return len; 
    }

    int maxLen() {
        int max = -1;
        for(int i=0; i<bslen-1; i++) {
            int curLen = complen(backStr[i], backStr[i+1]);
            if(curLen > max)
                max = curLen;
        }
        return max;
    }

    QSortString(string s) {
        bslen = s.size();
        backStr = new string[bslen];
        //generate back_array
        for(int i=0; i<bslen; i++) {
            backStr[i] = s.substr(i, bslen-i);
        }    
        qsort(backStr, 0, bslen-1);
    }

    //Must delete backStr or it will occur memory leak problem
    ~QSortString() {
        delete[] backStr;
    }
};

int n[4] = {0};

int main()
{
    string s;
    cin >> s;
    QSortString *qs = new QSortString(s);
    cout << qs->maxLen() << endl;
    delete qs;

    return 0;
}
