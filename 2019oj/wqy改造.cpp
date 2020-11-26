#include <cstdio>
const double eps = 1e-6;
int main()
{
	double k, j, q, a;
	int t;
	freopen("wqy改造随机.in","r", stdin);
	freopen("wqy改造随机.out","w", stdout);
	while(~scanf("%d", &t)){
		while(t--){
			scanf("%lf %lf %lf %lf", &k, &j, &q, &a);
			while(a > eps){
				a /= 10;
				k += a;
				j += a;
				q += a;
			}
			printf("%.3f %.3f %.3f\n", k / 100 > 1 ? 1 : k / 100, j / 100 > 1 ? 1 : j / 100, q / 100 > 1? 1 : q / 100);
		}
	}
	return 0;
}
