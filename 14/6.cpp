#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
// 6 使用map，按学号，依次输出学生姓名和成绩。
class Stu
{
private:
    string name;
    double score;
public:
    Stu():name("NULL"),score(0){}
    Stu(string _name, double _score):name(_name),score(_score){}
    friend ostream& operator << (ostream &os, const Stu student)
    {
        cout << "姓名：" << student.name << endl;
        cout << "成绩：" <<student.score<< endl;
        return os;
    }
};

int main()
{
    map<ll, Stu> s;
    Stu stu1("huhongyu", 96);
    Stu stu2("张三", 89);
    Stu stu3("李四", 92);
    s[201805120114] = stu1;
    s[201805122556] = stu2;
    s[132453123151] = stu3;
    map<ll, Stu>::iterator i;
    for (i = s.begin(); i != s.end(); i++)
    {
        cout << "学号："<< i->first <<endl;
        cout << i -> second << endl;
    }
}

