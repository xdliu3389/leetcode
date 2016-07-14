/*
	Problem:
		quick sort

	How to:
		basic quick sort algorithm. Need review it and remember it.

	Tip:
		The program seems doesn't work for the array whos len is less than 4. And i don't do the error check to the array.
		I think when the len of array is less than 10000, we can use some other sort algorithm which is easy implemented such as 
		bubble sort, choose sort.
*/

#include <iostream>

using namespace std;

class quick_sort {
public:
	int partitionArray(int n[], int l, int r) {
		int i=l, j=r;
		int flag = n[i];
		while(i < j) {
			//Coz we choose the l as the flag, so we move the right element first
			while(i<j && n[j]>flag)
				j--;
			if(i < j)
				n[i++] = n[j];

			//Move left element.
			while(i<j && n[i]<flag)
				i++;
			if(i < j)
				n[j--] = n[i];
		}
		n[i] = flag;
		return i;
	}

	void qsort(int n[], int l, int r) {
		if(l < r) {
			int mid = partitionArray(n, l, r);
			qsort(n, l, mid-1);
			qsort(n, mid+1, r);
		}
	}
};

int main()
{
	int n[] = {4,6,2,5,1,3,9,7,8,0};
	int len = sizeof(n) / sizeof(n[0]);
	quick_sort qs;
	qs.qsort(n, 0, len-1);	
	for(int i=0; i<len; i++) {
		cout << n[i] << " ";
	}
	cout << endl;
	return 0;
}
