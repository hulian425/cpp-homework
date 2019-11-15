/*
求圆形和长方形的面积。请抽象出一个公共的基类为抽象类，
在其中定义求面积的纯虚函数，并定义两个成员变量，
分别表示长方形的长和宽（或表示圆形的半径），派生出子类后，
在2个子类中重写求面积的方法。*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#define pi 3.141596
using namespace std;

class convex {
public:
	virtual void showarea()const = 0;
};

class circle :public convex
{
private:
	double r;
public:
	circle (double _r = 0):r(_r){}
	void showarea()const
	{
		cout << "The circle area is " << pi * r * r << endl;
	}
};

class rectangle :public convex
{
private:
	double a,b;
public:
	rectangle(double _a = 0, double _b = 0):a(_a),b(_b){}
	void showarea()const
	{
		cout << "The rectangle area is " << a*b << endl;
	}
};

int main()
{
	circle a(3);
	a.showarea();
	rectangle b(4, 6);
	b.showarea();

}
