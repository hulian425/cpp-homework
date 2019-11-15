/*以手动寻找的方式，通过子类对象找到以下2个虚函数的入口地址并调用。*/

#include <iostream>
#include <algorithm>
using namespace std;

class Class {
	virtual void f() { cout << "Class::f" << endl; }
	virtual void g() { cout << "Class::g" << endl; }
};
class SubClass : public Class {

};

typedef void(*Fun)();
int main()
{
	/*
	typedef void(*Fun)(void); 
 
      Base b;
 
       Fun pFun = NULL;
 
        cout << "虚函数表地址：" << (int*)(&b) << endl;
 
        cout << "虚函数表 — 第一个函数地址：" << (int*)*(int*)(&b) << endl;
 
        // Invoke the first virtual function 
 
        pFun = (Fun)*((int*)*(int*)(&b));
 
        pFun();
		*/
	SubClass a;
	Fun pFun = NULL;
	pFun = (Fun) * ((int*) * (int*)(&a + 0));
	pFun();
	pFun = (Fun) * ((int*) * (int*)(&a + 0) + 1);
	pFun();
	
}
