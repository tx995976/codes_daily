#include <cstdio>

const int maxn = 1005;
bool dp[maxn][maxn];
bool vis[maxn][maxn];

bool call(int i, int j)
{
	if(vis[i][j]){
		return dp[i][j];
	}
	vis[i][j] = true;
	bool tmp = false;
	for(int k = j - 1; k >= 2 * j - i - 1 && k >= 0; k--){
		tmp |= call(j, k);
	}
	dp[i][j] = !tmp;
	return dp[i][j];
}
void init()
{
	for(int i = 1; i < maxn; i++){
		dp[i][0] = vis[i][0] = true;
		for(int j = 1; j < maxn; j++){
			dp[i][j] = vis[i][j] = false;
		}
	}
}
int main()
{
	int t, n;
	while(~scanf("%d", &t)){
		init();
		while(t--){
			scanf("%d", &n);
			call(n, n - 1) ? printf("hyy\n") : printf("wqy\n");
		}
	}
	return 0;
}
