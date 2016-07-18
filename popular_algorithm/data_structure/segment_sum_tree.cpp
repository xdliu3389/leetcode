/*
 * Important data_structure!!!
 *
 *  Problem:
 *      We have an array arr[0 . . . n-1]. 
 *      We should be able to1 Find the sum of elements from index l to r where 0 <= l <= r <= n-12 Change value of a specified element of the array to a new value x. 
 *      We need to do arr[i] = x where 0 <= i <= n-1.
 *
 *  How to:
 *  Solution1:
 *      getSum by loop the array. set value directly with index. The update time is : O(1), the getSum time is : O(n);
 *      (attention: Though this can be implemented quickly, but it's not suit for problem with many getSum operations
 *
 *  Solution2:
 *      create another array sumVec to store the sum from start to i at the ith index in the array. The update time is : O(n)(One need update the whole sumVec), the getSum time is : O(1)
 *      (attention: It's not suit for problem with many update operations)
 *  
 *  Is there a method that the update and getSum has the near time complexity?
 *
 *  !!!Solution3:
 *      We use a data_structure called segment_tree to store data. And it's a complete binary tree which can be implemented by array.
 *      You can refer to segment_tree.png to make a big picture of segment_tree.
 *      Because of the feature of complete binary tree, the left leaf node's index is 2*index+1, and the right one's index is 2*index+2;
 * 
 * */

#include <iostream>
#include <cmath>

using namespace std;


/*
 * se, ss ---> The begin index and end index of st
 *  l, r  ---> The begin idnex and end index of v
 *    vid ---> The index of v[]
 *    sid ---> The index of st[]
 *
 * */
class SegmentTree {
public:
    //st is pointer to array that store the sum
    //stLen is the len of st
    int *st;
    int stLen;

    void printSt() 
    {
        for(int i=0; i<stLen; i++) {
           cout << st[i] << " ";
        }
        cout << endl;
    }

    void printV(int v[], int n)
    {
        for(int i=0; i<n; i++) {
            cout << i<<":"<<v[i] << " ";
        }
        cout << endl;
    }

    //We build the segmentTree recursively.
    void buildSegmentTree(int v[], int l, int r, int *st, int sid)
    {
        int sum = 0;
        for(int i=l; i<=r; i++) {
            sum = sum + v[i];
        }    
        st[sid] = sum;
        int mid = (l+r) / 2;
        if(r > l) {
            buildSegmentTree(v, l, mid, st, 2*sid+1);
            buildSegmentTree(v, mid+1, r, st, 2*sid+2);
        }
    }

    //We update all the nodes relative to changed value recursively.
    void update(int v[], int ss, int se, int sid, int vid, int val)
    {
		//If we the val is equal to diff, then this if block can be omited
        if(0 == sid) {
            int temp = v[vid];
            v[vid] = val;
            val = val - temp;
        }
        if(ss<=vid && se>=vid) {
            st[sid] += val;
        } 
        if(ss < se) {
            int mid = (se + ss) / 2;
            update(v, ss, mid, sid*2+1, vid, val);
            update(v, mid+1, se, sid*2+2, vid, val);
        }
    }

    //getSum function.
    int getRangeSum(int v[], int ss, int se, int l, int r, int id)
    {
        if(l>se || r<ss)
            return 0;
        //if l==r, than return the v[l] directly.
        if(l == r)
            return v[l];
        else if(l<=ss && r>=se)
            return st[id];
        int mid = (ss+se)/2;
        return getRangeSum(v, ss, mid, l, r, 2*id+1)+\
             getRangeSum(v, mid+1, se, l, r, 2*id+2);

    } 

    SegmentTree(int v[], int n)
    {
        //There are n element of v, so the height of vector tree is ceil(log2(n)), so the stLen is at most pow(2, ceil(log2(n)));
        int t = ceil(log2(n));
        stLen = (int)pow(2, t) ;
        st = new int[stLen];
        buildSegmentTree(v, 0, n, st, 0);
    } 


};

int main()
{
    int v[] = {1,4,5,2,7,6,9,8,0,3};
    int n = sizeof(v) / sizeof(v[0]);

    SegmentTree s(v, n-1);
    cout << "printSt:" << endl;
    s.printSt();
    cout << "printV:" << endl;
    s.printV(v, n);
    cout << s.getRangeSum(v, 0, n-1, 4, 7, 0) << endl;
    s.update(v, 0, n-1, 0, 6, 10);
    cout << "printSt:" << endl;
    s.printSt();
    cout << "printV:" << endl;
    s.printV(v, n);
    cout << s.getRangeSum(v, 0, n-1, 4, 7, 0) << endl;

    return 0;
}
