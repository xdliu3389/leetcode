/*
	Best:	O(n*logn)
	Worst:  O(n*logn)
	Average:O(n*logn)
	Space:	O(n)
		
*/

#include <iostream>
#include <vector>
#define MAX_INT 10000000
using namespace std;


void Merge(int *a, int p, int q, int r)
{
	int n1 = q-p+1;
	int n2 = r-q;
	int *L = new int[n1+1];
	int *R = new int[n2+1];
	int i, j, k;
	
	for (i=0; i<n1; i++){
		L[i] = a[p+i];
	}
	for (j=0; j<n2; j++){
		R[j] = a[q+j+1];
	}
	L[n1] = 10000000;
	R[n2] = 10000000;

	for (i=0, j=0, k=p; k<=r; k++)
	{
		if (L[i]<=R[j])
		{
			a[k] = L[i];
			i++;
		}else{
			a[k] = R[j];
			j++;
		}
	}

	delete []L;
	delete []R;
}

void MergeSort(int *a, int p, int r)
{
	if (p<r)
	{
		int q = (p+r)/2;
		MergeSort(a, p, q);
		MergeSort(a, q+1, r);
		Merge(a, p, q, r);
	}
}


int main()
{
	int a[] = {6,9,3,8,5,1,4,2,7,0};
	int n = sizeof(a) / sizeof(a[0]);
	cout << "n:" << n << endl;
	MergeSort(a, 0, n-1);

	for(int i=0; i<n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	
	return 0;
}
