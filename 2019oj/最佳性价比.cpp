#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10005;
struct Point{
	int i;
	double w, p, b;
	bool operator <(Point &a)const{
		return b == a.b ? (w == a.w ? a.i > i : w > a.w) : b > a.b;
		//return b > a.b;
	}
}point[maxn];
int main()
{
	int n, t;
	//freopen("最佳性价比随机.in","r", stdin);
	//freopen("最佳性价比随机.out","w", stdout);
	while(~scanf("%d", &t)){
		while(t--){
			scanf("%d", &n);
			for(int i = 0; i < n; i++){
				scanf("%lf %lf", &point[i].w, &point[i].p);
				point[i].b = point[i].p == 0 ? 1e30 : point[i].w / point[i].p;
				point[i].i = i + 1;
			}
			sort(point, point + n);
			printf("%d\n", point[0].i);
		}
	}
	return 0;
}
