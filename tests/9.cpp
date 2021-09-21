#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	double a,b,c;
	double p,ans;
	scanf("%lf %lf %lf",&a,&b,&c);
	p=0.5*(a+b+c);
	ans=sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%.1lf",ans);
	return 0;
}