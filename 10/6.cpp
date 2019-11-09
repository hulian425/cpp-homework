#include<stdio.h>
#include <iostream>
using namespace std;
#include <cmath>

class String
{
public:
	// 构造函数的重载
	String()
	{
		_size = 0;
		_string = 0;
	}
	String(const char* a)
	{
		_size = strlen(a);
		_string = new char[_size + 1];
		strcpy(_string, a);
	}
	String(const String& a)
	{
		_size = a._size;
		_string = new char[_size + 1];
	strcpy(_string, a._string);
	}
	// 析构函数
	~String()
	{
		_size = 0;
		delete []_string;
	}
	// 赋值操作符+的重载
	String operator+(const String& a)
	{
		String t;
		t._size = a._size + _size;
		t._string = new char[t._size + 1];
		strcpy(t._string, _string);
		strcat(t._string, a._string);
		return t;
	}
	String operator+(const char* a)
	{
		String t;
		t._size = strlen(a) + _size;
		t._string = new char[t._size + 1];
		strcpy(t._string, _string);
		strcat(t._string, a);
		return t;
	}
	String& operator=(const String& a)
	{
		
		_size = a._size;
		_string = new char[_size + 1];
		strcpy(_string, a._string);
		return *this;

	}
	String operator=(const char* a)
	{
		_size = strlen(a);
		_string = new char[_size + 1];
		strcpy(_string, a);
		return *this;
	}
	// 重载的下标[]操作符
	char& operator[](int n) const
	{
		return _string[n];
	}
	// 等于操作符==的重载集合
	bool operator==(const char* a) const
	{
		if (strcmp(_string, a) != 0) {
			return false;
		}

		return true;
	}
	bool operator==(const String& a) const
	{
		if (strcmp(_string, a._string) != 0) {
			return false;
		}

		return true;
	}
	// 重载<<
	friend ostream& operator<<(ostream& os, const String& a)
	{
		os << a._string << endl; 
		return os;
	}
	// 接口
	int size() { return _size; }
	char* c_str() { return _string; }
private:
	int _size;
	char* _string;
};

int main()
{
	const char* q = "hello world";
	String a(q);
	cout << a;
	String b("hello c++");
	cout << b;
	cout << a + b;
	a = b;
	cout << "after a = b, a = " << a;
	String c;
	c = "fjaslej";
	cout << c;
	cout << "a == c " << (a == c) << endl;
	c = a;
	cout << "after c = a " << (a == c) << endl;
	return 0;
}

