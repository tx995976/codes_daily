#include <cstdio>
#include <cstring>
const int maxm = 105;
struct Point{
	int v, w;
}point[maxm];

int main()
{
	int n, m, t;
	//freopen("lru算法随机.in","r", stdin);
	//freopen("lru算法随机.out","w", stdout);
	while(~scanf("%d", &t)){
		while(t--){
			memset(point, 0, sizeof(point));
			scanf("%d %d", &n, &m);
			int temp;
			for(int i = 0; i < n; i++){
				scanf("%d", &temp);
				int min = 0x7f7f7f7f, flag = 0, minj;
				for(int j = 0; j < m; j++){
					if(point[j].w == temp){
						flag = 1;
						point[j].v = i;
						break;
					}
					if(!point[j].w){
						flag = 1;
						point[j].v = i;
						point[j].w = temp;
						break;
					}
					if(point[j].v < min){
						min = point[j].v;
						minj = j;
					}
				}
				if(!flag){
					point[minj].w = temp;
					point[minj].v = i;
				}
			}
			for(int i = 0; i < m; i++){
				printf("%d %d\n", i + 1, point[i].w);
			}
		}
	}
	return 0;
}
