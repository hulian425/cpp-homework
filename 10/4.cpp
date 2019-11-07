#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
/*设计一个三角形类Triangle，包含三角形三条边长的私有数据成员，
另有一个重载运算符“+”，以实现求两个三角形对象的面积之和。

上题中的重载运算符“+”友元函数只能返回两个三角形的面积之和，
不能计算三个三角形的面积之和，改进一下，使之能计算任意多个三角形的面积之和。*/

class Triangle
{public:
	Triangle(double _a = 0, double _b = 0, double _c = 0)
	{
		a = _a;
		b = _b;
		c = _c;
		area = 0.5 * sqrt(4 * a * a * b * b - (a * a + b * b - c * c) * (a * a + b * b - c * c));
	}

	friend double operator + (const Triangle & t1, const Triangle &t2)
	{
		return t1.area + t2.area;
	}
	friend double operator + (double s, const Triangle & t3)
	{
		return s +t3.area;
	}
	friend ostream & operator << (ostream & os , const Triangle &t)
	{
		os << "三角形三边长分别为 " << t.a << " " << t.b << " " << t.c <<endl;
		os << "三角形面积为 " << t.area << endl;
		return os;
	}
private:
	double a;
	double b;
	double c;
	double area;
};

int main()
{
	Triangle t1(3, 4,5);
	Triangle t2(1, 1, sqrt(2));
	Triangle t3(12, 13, 15);
	cout << t1 <<t2 <<t3;
	cout << t1 + t2 + t3 << endl;
	system("pause");
}
