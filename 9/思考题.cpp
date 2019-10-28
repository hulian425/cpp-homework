#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
#define M_PI acos(-1.0)
const double eps = 1e-4;
inline int cmp(double x)
{
	if (fabs(x) < eps) return 0;
	if (x > 0) return 1;
	return -1;
}
inline double f(double x)
{
	return 0.7 * x + 8 * sin(6 * x) + 9 * cos(3 * x);
}
inline double f1(double x)
{
	return 0.7 + 48 * cos(6 * x) - 27 * sin(3 * x); // T = 2 * pai / 3
}
int main()
{
	double i;
	double maxn = 0;
	double j = 0;
	double ans = 1;
	for (i = 0.2; i <= 0.21; i += 0.000001)
	{
		//printf("i = %lf , f(x) = %lf\n", i, f1(i));
		if (cmp(f1(i)) == 0)
		{
			j = i;
			break;
		}

	}
	printf("j = %lf\n", j);
	for (; j <= 10; j = j + (2 * M_PI / 3.0))
	{
		if (f(j) > maxn)
		{
			ans = j;
			maxn = f(j);
		}
	}
	printf("max_x = %lf, f(x) = %lf\n", ans, maxn);
	return 0;
}


/*#include <iostream>
#include <cmath>
#include <ctime>
#include<cstdio>
using namespace std;
const double Pi = acos(-1.0);

// 令t=3x, f(t)=(7/30)t+8sin(2t)+9cos(t) 0<=t<=30
// f'(t)=7/30+16(1-2sin(t)*sin(t))-9sin(t)
// 令u=sin(t) f'(u)=7/30+16(1-2*u*u)-9u)=-32*u*u-9u+487/30 -1<=u<=1
// 令f'(u)=0 u1=(sqrt(32383*1.0/15)-9)/64, u2=(-9-sqrt(32383*1.0/15))/64
// 求得近似值 u1=-0.8666188411  u2=0.5853688411
// 当f'(t)=0时 t=arcsin(u)+2kπ或 π-arcsin(u) +2kπ k是整数
// 最大值在t=0,t=30以及f'(t)=0中取
inline double g(double x){//找到0到2π之间与x相差2kπ的值
	if (x >= 0)
		return x-floor(x/(2*Pi))*2*Pi;
	return ceil((-x)/(2*Pi))*2*Pi+x;
}
inline double f(double t){
	double x = t/3;
	return 0.7*x + 8*sin(6*x) + 9*cos(3*x);
}
int main(){
	clock_t start = clock();
	double i;
	double max = f(10.0) > f(0.0)? f(10.0): f(0.0);
	double u1 = (sqrt(32383*1.0/15)-9)/64;
	double u2 = (-9-sqrt(32383*1.0/15))/64;
	double t1 = asin(u1), t2 = Pi-asin(u1), t3 = asin(u2), t4 = Pi-asin(u2);
	t1 = g(t1); t2 = g(t2); t3 = g(t3); t4 = g(t4);
	for (i = t1; i <= 30; i += 2*Pi)
		if (f(i) > max)
			max = f(i);
	for (i = t2; i <= 30; i += 2*Pi)
		if (f(i) > max)
			max = f(i);
	for (i = t3; i <= 30; i += 2*Pi)
		if (f(i) > max)
			max = f(i);
	for (i = t4; i <= 30; i += 2*Pi)
		if (f(i) > max)
			max = f(i);
	printf("%.10f\n", max);
	clock_t elapased = clock() - start;
	printf("time: %.10f s.\n", (double)elapased/CLOCKS_PER_SEC);
}*/
