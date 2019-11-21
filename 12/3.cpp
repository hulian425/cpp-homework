/*根据main()写模板类
void main()
{
	Sample<int> s1(5),s2(8),s3;
	if(s1==s2)
	{
		cout<<"s1和s2相等";
	}
	s3=s1-s2;
	--s3;
	s3.show();
} */

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;



template<class T> class Sample{
    private:
        T a;
    public:
        Sample()
        {
            a = 0;
        }
        Sample(T _a)
        {
            a = _a;
        }
        void show()
        {
            cout << a << endl;
        }
        void operator ++()
        {
            a += 1;
        }
        void operator --()
        {
            a -= 1;
        }

        Sample operator + (const Sample & _num)
        {
            Sample t;
            t.a = a + _num.a;
            return t;
        }
        Sample operator - (const Sample & _num)
        {
            Sample t;
            t.a = a - _num.a;
            return t;
        }
        friend bool operator == (const Sample & _a, const Sample & _b)
        {
            return _a.a == _b.a;
        }
};

int main()
{
    Sample<int> s1(5),s2(8),s3;
	if(s1==s2)
	{
		cout<<"s1和s2相等";
	}
	s3=s1-s2;
	--s3;
	s3.show();
    /*double a[5] = {10.2, 3.6, 3.4, 1.5, 8.9};
    int b[5] = {1,8,66,89,46};
    cout << "minn = " << mean(a,5) << endl;
    cout << "minn = " << mean(b,5) << endl;*/
}
