#include<stdio.h>
#include <iostream>
using namespace std;
#include <cmath>
const double eps = 1e-8;
int cmp(double x)
{
	if (fabs(x) < eps) return 0;
	if (x > 0) return 1;
	return -1;
}
class point
{
public:
	point(){}
	point(double a, double b) :x(a), y(b){}
	friend point operator + (const point& a, const point& b)
	{
		return point(a.x + b.x, a.y + b.y);
	}
	point operator = (const point& a)
	{
		x = a.x;
		y = a.y;
		return point(x, y);
	}
	friend bool operator == (const point& a, const point& b)
	{
		return cmp(a.x - b.x) == 0 && cmp(a.y - b.y) == 0;
	}
	friend ostream& operator << (ostream& os, const point& a)
	{
		os << "x = " << a.x << " y = " << a.y << endl;
		return os;
	}
private:
	double x, y;
};
int main()
{
	point a(3.5, 5);
	cout << a;
	point b(2, 5);
	cout << b;
	cout << "a + b " << a + b;
	point c(6, 7);
	cout << "a + b + c " << a + b + c ;
	cout  << "a == b " << (a == b) << endl;
}
