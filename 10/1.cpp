#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

class MyInt
{
public:
	MyInt(int _x = 0){
		x = _x;
	}
	MyInt operator = (int _x)
	{
		MyInt t;
		x = _x;
		t.x = x;
		return t;
	}
	MyInt& operator = (MyInt _x)
	{
		MyInt t;
		x = _x.x;
		t.x = x;
		return t;
	}
	bool operator == (const MyInt &_x)const
	{
		return x == _x.x;
	}
	bool operator == (int _x)const
	{
		return x == _x;
	}
	bool operator < (const MyInt &_x)const
	{
		return x < _x.x;
	}

	bool operator < (int _x)const
	{
		return x < _x;
	}

	bool operator > (int _x)const
	{
		return x > _x;
	}

	bool operator > (const MyInt &_x)const
	{
		return x > _x.x;
	}

	friend ostream& operator << (ostream &os, const MyInt _int)
	{
		os << _int.x;
		return os;
	}

	void operator ++()
	{
		x += 1;
	}
	
	MyInt operator + (const MyInt & _int)
	{
		MyInt t;
		t.x = x + _int.x;
		return t;
	}
private:
	int x;
};
int main()
{
	MyInt a;
	cout << "a = "<<a << endl;
	MyInt b(3);
	MyInt c = 6;
	cout << "b = "<<b << endl;
	cout << "c = "<<c << endl;
	cout << "b == 6 " << (b == 3) << endl;
	c = 3; a = 3;
	cout << "b = a = c = 3  " << ((b == a) && (a == c)) << endl;
	c = 6;
	a = c;
	cout << "a = "<< a << " c = " << c << endl;

	cout << "a < b " << (a < b) << endl;
	cout << "a > b " << (a > b) << endl;

	a++;
	cout << "a++ a = " << a << endl;
	a = 1, b = 2, c = 3;
	a = b = c;
	cout << "a = " << a  << " b = " <<b <<endl; 
	c = a + b + c;
	cout << "c = a + b + c " << c << endl;
	system("pause");
}
