#include<vector>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

char* erase_a(char *a)
{
    int i;
    for (i = 0; a[i] != 0; i++)
    {
        if (a[i] == 'a')
        {
            int j;
            for (j = i; a[j] != 0; j++)
                a[j] = a[j + 1];
            i--;
        }
    }
    return a;
}
int main()
{
    cout << "test\n";
    char test1[] = "alsjfalsjf";
    cout << test1 << endl;
    cout << "after implementation function erase_a\n";
    cout << erase_a(test1) << endl;

    char test2[] = "aabaaaa";
    cout << test2 << endl;
    cout << "after implementation function erase_a\n";
    cout << erase_a(test2) << endl;

    char test3[] = "aaaaaa";
    cout << test3 << endl;
    cout << "after implementation function erase_a\n";
    cout << erase_a(test3) << endl;
}
