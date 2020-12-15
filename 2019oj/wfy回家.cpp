#include <cstdio>
#include <cmath>
const int maxn = 105;
const double pi = acos(-1), eps = 1e-9;
struct Point{
	double x, y, r, dis;
};
double dist(Point a, Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool judge(double a, double b, double c)
{
	return (a * a + b * b - c * c) < 0;
}
int main()
{
	Point st, ed, tmp;
	int n, t;
	freopen("wfy指社昧字.in","r", stdin);
	//freopen("wfy指社昧字.out","w", stdout);
	while(~scanf("%d", &t)){
		while(t--){
			scanf("%d", &n);
			scanf("%lf %lf %lf %lf", &st.x, &st.y, &ed.x, &ed.y);
			double k = (ed.y - st.y) / (ed.x - st.x), p;
			double b = -(k * st.x - st.y);
			double ans = sqrt((ed.y - st.y) * (ed.y - st.y) + (ed.x - st.x) * (ed.x - st.x));
			for(int i = 0; i < n; i++){
				scanf("%lf %lf %lf", &tmp.x, &tmp.y, &tmp.r);
				tmp.dis = fabs(k * tmp.x - tmp.y + b) / sqrt(k * k + 1);
				double a1 = dist(st, tmp), b1 = dist(ed, tmp), c1 = dist(st, ed);
				if(judge(a1, c1, b1) || judge(b1, c1, a1)){
					continue;
				}
				if(tmp.dis < tmp.r){
					p = sqrt(tmp.r * tmp.r - tmp.dis * tmp.dis);
					ans += (2 * asin(p / tmp.r) * tmp.r - 2 * p);
				}
			}
			printf("%.3f\n", ans);
		}
	}
	return 0;
 } 
