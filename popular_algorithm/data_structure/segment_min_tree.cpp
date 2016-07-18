/*
 * Important data_structure!!!
 *
 *  This problem is extension of segment_sum_tree. And we change buildSegmentTree, update and getRangeMin to fit the problem:
 *      Find the minimum in a given block of a array.
 *
 * */

#include <iostream>
#include <cmath>

using namespace std;


/*
 * se, ss ---> The begin index and end index of array at st[sid]
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
            cout << i<<":"<<v[i] << "   ";
        }
        cout << endl;
    }

    //We build the segmentTree recursively.
    void buildSegmentTree(int v[], int l, int r, int *st, int id)
    {
        int min = v[l];
		//Loop to find the minimum number in the range of l and r
        for(int i=l+1; i<=r; i++) {
            if(v[i] < min)
				min = v[i];
        }    
        st[id] = min;
        int mid = (l+r) / 2;
        if(r > l) {
            buildSegmentTree(v, l, mid, st, 2*id+1);
            buildSegmentTree(v, mid+1, r, st, 2*id+2);
        }
    }

    //We update all the nodes relative to changed value recursively.
    void update(int v[], int ss, int se, int sid, int vid, int val)
    {
		//If wen pass the diff here, than we dopn
        if(ss<=vid && se>=vid) {
            v[vid] = val;
			if(val < st[sid])
				st[sid] = val;
        } 
        if(ss < se) {
            int mid = (se + ss) / 2;
            update(v, ss, mid, sid*2+1, vid, val);
            update(v, mid+1, se, sid*2+2, vid, val);
        }
    }

    //getSum function.
    int getRangeMin(int v[], int ss, int se, int l, int r, int sid)
    {
        if(l>se || r<ss)
            return 100;
        if(l == r)
            return v[l];
        //if l<=ss and r>=se, this means the minumum of [ss,se] is the minumum of [l, r]. So return it
        else if(l<=ss && r>=se)
            return st[sid];
        int mid = (ss+se)/2;
        return min(getRangeMin(v, ss, mid, l, r, 2*sid+1), getRangeMin(v, mid+1, se, l, r, 2*sid+2));

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
    s.printV(v, n);
	cout << s.getRangeMin(v, 0, n-1, 3, 7, 0) << endl;
    s.update(v, 0, n-1, 0, 4, 1);
    s.printSt();
    s.printV(v, n);
	cout << s.getRangeMin(v, 0, n-1, 3, 7, 0) << endl;
    return 0;
}
