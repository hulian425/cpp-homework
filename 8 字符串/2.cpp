#include<vector>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

int MyStrlen(char s[])
{
    int i;
    for (i = 0; s[i] != 0; i++);
    return i;
}

char* MyStrcpy(char *destination, const char *source)
{
    int i;
    for (i = 0; source[i] != 0; i++)
        destination[i] = source[i];
    destination[i] = 0;
    return destination;
}

char *MyStrupr(char *str)
{
    for (int i = 0; str[i] != 0; i++)
    {
        if ( 'a' <= str[i] && str[i] <= 'z')
            str[i] = str[i] + 'A' - 'a';
    }
    return str;
}
char * MyStrcat(char *destination, const char* source)
{
    int i, j;
    for (i = 0; destination[i] != 0; i++);
    for (j = 0; source[j] != 0; j++, i++)
    {
        destination[i] = source[j];
    }
    destination[i] = 0;
    return destination;
}
int main()
{
    cout << "test MyString\n";
    char a[] = "hello";
    cout << "The length of 'hello' is :\n";
    cout << MyStrlen(a) << endl;

    cout << "strcpy test\n";
    char b[10];
    cout << MyStrcpy(b,a) << endl;

    cout << "strupr test\n";
    char c[] = "I love cpp**";
    cout << MyStrupr(c) << endl;

    cout << "strcat test\n" << endl;
    cout << MyStrcat(a,c) << endl;
    return 0;
}
