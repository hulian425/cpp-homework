#include<vector>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

char* String_b(char *a, char *b)
{
    bool is[200];
    int j = 0;
    int len = strlen(a) + strlen(b);
    char* c = new char [200];
    for (int i = 0; i < 200; i++)
        is[i] = false;
    for (int i = 0; a[i] != 0; i++)
    {
        is[a[i]] = true;
    }

    for (int i = 0; b[i] != 0; i++)
    {
        is[b[i]] = true;
    }
    for (int i = 0; i < 200; i++)
    {
        if (is[i])
            c[j++] = char(i);
    }
    c[j] = 0;
    return c;
}
int main()
{
    cout << "test\n";
    char a[] = "hello";
    char b[] = "look";
    cout << a << " " << b << endl;
    cout << "after implementation function String_b\n";
    cout << String_b(a, b) << endl;
    char aa[] = "";
    char ba[] = "look";
    cout << aa << " " << ba << endl;
    cout << "after implementation function String_b\n";
    cout << String_b(aa, ba) << endl;
}
