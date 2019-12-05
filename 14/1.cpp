#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    stack<char> s;
    for (char i = 'a'; i <= 'z'; i++)
    {
        s.push(i);
    }
    while (!s.empty())
    {
        printf("%c", s.top());
        s.pop();
    }
    cout << endl;
    return 0;
}
