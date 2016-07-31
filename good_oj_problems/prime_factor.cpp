/*
	问题:
		输入一个正整数, 从小到大输出它的所有质数因子.
	输入:
		180
	输出:
		2 2 3 3 5
*/

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void all_prime_factor(vector<int> &res, int N)
{
	while(N > 1) {
		// 质数的特点是：除了自己和1以外，不会被其他数整除.
		// 这里正好是从小到大输出, 这个循环是不会输出非质数的.
		// 因为对于非质数, 一定是2 3 5这些质数的倍数.这个循环遇到2 3等等能整除就跳出下一个循环.
		// Beautiful and clean code
		for(int i=2; i<=N; i++) {
			if(N % i == 0) {
				N = N / i;
				res.push_back(i);
				break;
			}
		}
	}	
}

void print_vec(vector<int> &res)
{
	for(int i=0; i<res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
}

int main()
{
	int N;
	vector<int> res;
	while(cin >> N) {
		all_prime_factor(res, N);
		print_vec(res);
		res.clear();
	}

	return 0;
}
