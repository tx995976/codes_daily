#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 100005;
struct Know{
	long long x, y;
	bool operator <(const Know &b) const
	{
		return x < b.x;
	}
};
Know know[maxn]; 
int main()
{
	int t, n, m;
	//freopen("hyyˢ�����.in","r", stdin);
	//freopen("hyyˢ�����.out","w", stdout);
	while(~scanf("%d", &t)){
		while(t--){
			scanf("%d %d", &n, &m);
			memset(know, 0, sizeof(know));
			for(int i = 0; i < n; i++){
				scanf("%lld %lld", &know[i].x, &know[i].y);
			}
			sort(know, know + n);
			long long ans = 0;
			long long max = 0, min = 2139062143;
			for(int i = 0; i < m; i++){
				ans += (know[i].x << 1);
				long long tmp = know[i].x + know[i].y;
				if(max < tmp){
					max = tmp;
				}
			}
			for(int i = m; i < n; i++){
				if(min > know[i].x - know[i].y){
					min = know[i].x - know[i].y;
				}
			}
			printf("%lld\n", ans - (know[m - 1].x * 2 - min > max ? know[m - 1].x * 2 - min : max));
		}
	}
	return 0;
}
