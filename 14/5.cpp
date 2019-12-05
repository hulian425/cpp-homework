#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <set>
using namespace std;

// 将一些无序的小数放入set，并从小到大顺序输出。

int main()
{
    set<double> s;
    s.insert(3.4);
    s.insert(2.5);
    s.insert(0.5);
    s.insert(5.6);
    set<double>::iterator i;
    for (i = s.begin(); i != s.end(); i++)
    {
        cout << *i << endl;
    }
}

