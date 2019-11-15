/*以手动寻找的方式，通过子类对象找到以下2个虚函数的入口地址并调用。*/

#include <iostream>
#include <algorithm>
using namespace std;

class Base1 {
	virtual void f() { cout << "Base1::f" << endl; }
	virtual void g() { cout << "Base1::g" << endl; }
};
class Base2 {
	virtual void f() { cout << "Base2::f" << endl; }
	virtual void g() { cout << "Base2::g" << endl; }
};
class Base3 {
	virtual void f() { cout << "Base3::f" << endl; }
	virtual void g() { cout << "Base3::g" << endl; }
};
class Drive : public Base1, public Base2, public Base3 {

};

typedef void(*Fun)();
int main()
{
	Drive a;
	Fun pFun = NULL;
	pFun = (Fun) * ((int*) * (int*)(&a + 0));
	pFun();
	pFun = (Fun) * ((int*) * (int*)(&a + 0) + 1);
	pFun();
	pFun = (Fun) * ((int*) * ((int*)(&a) + 1) + 0);
	pFun();
	pFun = (Fun) * ((int*) * ((int*)(&a) + 1) + 1);
	pFun();
	pFun = (Fun) * ((int*) * ((int*)(&a) + 2) + 0);
	pFun();
	pFun = (Fun) * ((int*) * ((int*)(&a) + 2) + 1);
	pFun();
	
}
