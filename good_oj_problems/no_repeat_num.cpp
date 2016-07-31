/*
	问题：
		给一个整数, 从右向左输出各个位上的值.每个数只输出一次.
	输入：
		219348931
	输出：
		139842
*/

#include <iostream>

using namespace std;

int main()
{
	// 最开始想到的是用map和vector结合解决
	// 但是仔细想想发现一个10元素的int数组就搞定了
	// 以后遇到这种类似问题首先想想普通的int数组能不能搞定.
	int a[10] = {0};
	int N;
	int res = 0;
	while(cin >> N) {
		res = 0;
		while(N != 0) {
			if(a[N%10] == 0) {
				res = res * 10 + N%10;
				a[N%10]++;
			}
			N = N / 10;
		}
		cout << res << endl;
	}
}
