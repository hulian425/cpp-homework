/*template<class T>
T mean(T x[],int n)*/

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;



template<class T>
T mean(T x[],int n)
{
    T minn = x[0];
    for (int i = 0; i < n; i++)
    {
        minn = min(x[i], minn);
    }
    return minn;
}
int main()
{
    double a[5] = {10.2, 3.6, 3.4, 1.5, 8.9};
    int b[5] = {1,8,66,89,46};
    cout << "minn = " << mean(a,5) << endl;
    cout << "minn = " << mean(b,5) << endl;
}
