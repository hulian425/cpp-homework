#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <list>
#include<numeric>
#include <deque>
using namespace std;

typedef long long ll;

// 用deque，存储用户输入的N个小数，再依次打印并输出这些小数的均值


int main()
{
	deque<float> a;
	int N;
	cout << "你要输入几个数\n";
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		float t;
		cin >> t;
		a.push_back(t);
	}
	float ans = 0.0;
	while (!a.empty())
	{
		cout << a.front() << " ";
		ans += a.front();
		a.pop_front();
	}
	puts("");
	cout << "均值\n";
	cout << ans/N << endl;

}
