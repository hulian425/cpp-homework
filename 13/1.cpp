#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <list>
#include<numeric>
#include <deque>
#include <vector>
using namespace std;

typedef long long ll;

// 用deque，存储用户输入的N个小数，再依次打印并输出这些小数的均值


int main()
{
	vector<int> a;
	for (int i = 100; i <= 200; i++)
	{
		a.push_back(i);
	}
	for (auto i = a.begin(); i < a.end(); i++)
	{
		if (*i % 7 == 0)
		{
			cout << *i << endl;
		}
	}
	return 0;
}
