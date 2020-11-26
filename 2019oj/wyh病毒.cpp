/*
最近，有一种叫做twt的病毒正在肆意蔓延，所以我们要尽量封锁这个病毒的蔓延。已知在一个村庄里一共有n个人，有m个人被确定感染了，但是我们不知道
他们和谁接触过。已知该病毒在一定范围内才会传播，经过监控排查，我们得到了所有人与他人接触过的距离记录。现在我们需要知道有几人未被感染，请你计算出最终答案。
 输入
 第一行一个正整数t代表数据组数 t最大 = 10 
 每组数据第一行有三个用空格隔开的正整数代表村庄有n个人，有m个人已被感染，病毒传播范围为k n,m,k最大为1000
 接下去有很多行(行数最大为10000)，每行有三个用空格隔开的整数 代表a和b接触的距离为c    a,b最大为1000,c最大为10000且a不等于b
 当a b c都等于0 时，接下去一行有m个用空格隔开的正整数，代表已知被感染的人的编号（编号为1-n） 
输出
 每组数据输出一行包含一个整数，代表未被感染的人数  
*/
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 1005;
int e[maxn][maxn], vis[maxn], w[maxn];
void add(int a, int b, int c)
{
	if(e[a][b] > c){
		e[a][b] = e[b][a] = c;
	}
}
int main()
{
	//freopen("twt病毒随机.in","r", stdin);
	//freopen("twt病毒随机.out","w", stdout);
	int t, n, k, a, b, c, m, tmp, test1;
	while(~scanf("%d", &t)){
		while(t--){
			memset(vis, 0, sizeof(vis));
			memset(w, 0, sizeof(w));
			queue<int> q;
			memset(e, 0x7f, sizeof(e));
			scanf("%d %d %d", &n, &m, &k);
			while(scanf("%d %d %d", &a, &b, &c) && a && b && c){
				add(a, b, c);
			}
			int sum = n;
			for(int i = 0; i < m; i++){					
				scanf("%d", &tmp);
				w[tmp] = vis[tmp] = 1;  //标记病毒
				q.push(tmp);
				sum--;					//健康人数
			}
			while(!q.empty()){
				tmp = q.front();
				q.pop();
				for(int i = 1; i <= n; i++){
					if(!vis[i] && !w[i]){
						//printf("%d %d\n", tmp, e[tmp][i]);
						if(e[tmp][i] <= k){   //病毒携带者与所有未感染者逐个对比
							//printf("here\n");
							vis[i] = 1;
							w[i] = 1;
							q.push(i);  //被感染人重新入栈
							sum--;
							test1++;
							printf("%d \n",tmp);
						}
					}
				}
				//printf("t:%d\n", sum);
			}
			printf("%d %d\n", sum,test1);
			
		}
	}				
	return 0;
 } 
