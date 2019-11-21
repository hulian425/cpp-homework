/*编写一个对具有n个元素的数组x[]求平均值的程序，要求将求平均值的函数设计成函数模板。


}*/

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

template<typename T> double ave(T a[], int n)
{
    T sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum / n;
}
int main()
{
    double a[5] = {10.2, 3.6, 3.4, 1.5, 8.9};
    printf("ave = %.2lf\n", ave(a, 5));

    int b[5] = {1,8,66,89,46};
    printf("ave = %.2lf\n", ave(b, 5));
}
