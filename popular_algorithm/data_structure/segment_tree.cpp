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
            cout << v[i] << " ";
        }
        cout << endl;
    }

    //We build the segmentTree recursively.
    void buildSegmentTree(int v[], int l, int r, int *st, int id)
    {
        int sum = 0;
        for(int i=l; i<=r; i++) {
            sum = sum + v[i];
        }    
        st[id] = sum;
        int mid = (l+r) / 2;
        if(r > l) {
            buildSegmentTree(v, l, mid, st, 2*id+1);
            buildSegmentTree(v, mid+1, r, st, 2*id+2);
        }
    }

    //We update all the nodes relative to changed value recursively.
    void update(int v[], int se, int ss, int sid, int vid, int val)
    {
        if(0 == sid) {
            int temp = v[vid];
            v[vid] = val;
            val = val - temp;
        }
        if(se<=vid && ss>=vid) {
            st[sid] += val;
        } 
        if(se < ss) {
            int mid = (se + ss) / 2;
            update(v, se, mid, sid*2+1, vid, val);
            update(v, mid+1, ss, sid*2+2, vid, val);
        }
    }

    //getSum function.
    int getRangeSum(int ss, int se, int l, int r, int id)
    {
        if(l>se || r<ss)
            return 0;
        else if(l<=ss && r>=se)
            return st[id];
        int mid = (ss+se)/2;
        return getRangeSum(ss, mid, l, r, 2*id+1)+\
             getRangeSum(mid+1, se, l, r, 2*id+2);

    } 

    SegmentTree(int v[], int n)
    {
        //There are n element of v, so the height of vector tree is ceil(log2(n)), so the stLen is at most pow(2, ceil(log2(n)));
        int t = ceil(log2(n));
        stLen = (int)pow(2, t);
        st = new int[stLen];
        buildSegmentTree(v, 0, n, st, 0);
    } 


};

int main()
{
    int v[] = {1,4,5,2,7,6,9,8,0,3};
    int n = sizeof(v) / sizeof(v[0]);

    SegmentTree s(v, n-1);
    s.printSt();
    cout << s.getRangeSum(0, n-1, 0, n-1, 0) << endl;
    s.update(v, 0, n-1, 0, 4, 12);
    s.printSt();
    cout << s.getRangeSum(0, n-1, 0, n-1, 0) << endl;

    return 0;
}
