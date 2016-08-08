#include <iostream>

using namespace std;

//It's very tricky about l, mid and r.
//You got set r = mid-1 and l = mid+1 when the new loop, or the search will fail.
int binarySearch(int a[], int n, int target)
{
    int l=0, r=n-1, mid;
    while(l <= r) {
        mid = (l+r)/2;
        if(target == a[mid])
            return mid;
        else if(target<a[mid])
            r = mid-1;
        else
            l = mid+1;
    }
    return -1;
}

int main()
{
    int a[] = {1,2,3,4,4,4,4,4,4,5,6,7,8,9};
    cout << binarySearch(a, sizeof(a)/sizeof(a[0]), 2121);
    return 0;
}
