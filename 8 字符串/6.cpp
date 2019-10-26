#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class MyString{
public:
    MyString();
    MyString(char* _m);
    MyString(MyString &_m);
    ~MyString();
    int Strlen();
    char* Strupr();
    void Display();
private:
    char* str;
    int len;
};

MyString::MyString()
{
    len = 0;
    str = NULL;

}

MyString::MyString(char* _m)
{
    if(_m == NULL)
    {
        len = 0;
        str = new char [1];
        strcpy(str, "");
    }
    else
    {
        len = strlen(_m);
        str = new char [len + 1];
        strcpy(str, _m);
    }
}

MyString::MyString(MyString &_m)
{
    len = _m.len;
    str = new char [len + 1];
    strcpy(str, _m.str);
}

MyString::~MyString()
{
    if(str != NULL)
    {
        cout << "Destructor executed." <<endl;
        delete str;
        str = NULL;
        len = 0;
    }
}

int MyString::Strlen()
{
    return len;
}

char* MyString::Strupr()
{
    int i;
    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
    return str;
}

void MyString::Display()
{
    int i;
    for(i = 0; str[i] != '\0'; i++)
        cout << str[i];
    cout <<endl;
}

int main()
{
    int len1, len2, len3;
    MyString s1;
    MyString s2("abcsfafasede");
    MyString s3(s2);
    len1 = s1.Strlen();
    cout << "The length of s1 is " << len1 <<endl;
    len2 = s2.Strlen();
    cout << "The length of s2 is " << len2 <<endl;
    len3 = s3.Strlen();
    cout << "The length of s3 is " << len3 <<endl;

    s2.Strupr();
    s3.Strupr();

    s2.Display();
    s3.Display();

    return 0;
}
