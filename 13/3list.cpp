#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <list>
#include<numeric>
using namespace std;

typedef long long ll;

// 使用list，累加1 - 100

int main()
{
	list<int> a;
	for (int i = 1; i <= 100; i++)
	{
		a.push_back(i);
	}
	cout << accumulate(a.begin(), a.end(), 0) << endl;
}
