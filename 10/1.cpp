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
	void operator = (int _x)
	{
		x = _x;
	}
	void operator = (MyInt _x)
	{
		x = _x.x;
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
	system("pause");
}
