#include<vector>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

char* String_intersect(char *a, char *b)
{
    bool is[200];
    for (int i = 0; i < 200; i++)
        is[i] = false;
    for (int i = 0; a[i] != 0; i++)
    {
        is[a[i]] = true;
    }
    int j = 0;
    for (int i = 0; b[i] != 0; i++)
    {
        if (is[b[i]])
            {
                a[j++] = b[i];
                is[b[i]] = false;
            }
    }
    a[j] = 0;
    return a;
}
int main()
{
    cout << "test\n";
    char a[] = "hello";
    char b[] = "look";
    cout << a << " " << b << endl;
    cout << "after implementation function String_intersect\n";
    cout << String_intersect(a, b) << endl;
}
