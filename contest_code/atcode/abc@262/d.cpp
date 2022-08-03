//#动态规划
//@
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>
#include<cstring>

const int _mod = 998244353;
using ll = long long;


int arr[110];
ll dp[110][110][110];
ll ans = 0ll;

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        scanf(" %d", &arr[i]);

    for(int i = 1; i <= n; i++){
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1ll;
        for(int j = 0; j < n; j++)
            for(int k = 0; k <= i; k++)
                for(int l = 0; l < i;l++){
                    (dp[j+1][k][l] += dp[j][k][l]) %= _mod;
                    if(k != i)
                        (dp[j+1][k+1][(l+arr[j+1])%i] += dp[j][k][l]) %= _mod;
                }
        (ans += dp[n][i][0]) %= _mod;
    }
    printf("%lld\n", ans);
    return 0;
}