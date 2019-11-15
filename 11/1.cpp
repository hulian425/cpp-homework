/*求销售人员类和工程师的月薪。请抽象出一个基类--员工类，在员工类中声明一个虚函数，用来求月薪，
并定义两个成员变量，分别表示销售数量和工作天数。在子类中分别重写求月薪的虚函数。*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

class employee
{
private:
	int days;
	int num;
public:
	employee(int _days = 0, int _num = 0)
	{
		days = _days;
		num = _num;
	}
	virtual void showsalary()
	{
		cout << "salary is " <<endl;
	}
	int getdays()
	{
		return days;
	}
	int getnums()
	{
		return num;
	}
};

class Saleman :public employee
{
public:
	Saleman(int _days = 0, int num = 0) :employee(_days, num)
	{

	}
	void showsalary()
	{
		cout << "Saleman salary is " << getnums() * 100 << endl;
	}
};

class Engineer :public employee
{
public:
	Engineer(int _days = 0, int num = 0) :employee(_days, num)
	{

	}
	void showsalary()
	{
		cout << "Engineer salary is " << getdays() * 300 << endl;
	}

};

int main()
{
	Saleman a(30, 50);
	a.showsalary();
	Engineer b(30, 0);
	b.showsalary();
}
