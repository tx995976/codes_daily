# ABC263

## e. [Sugoroku 3](https://atcoder.jp/contests/abc263/tasks/abc263_e)

令$DP[i]$表示$i$到$N$的步数期望  
有
$$DP[i] = \frac{\sum_{j=i+1}^{A_{i}+i}DP[j]+A_i+1}{A_i}$$
[证明](https://atcoder.jp/contests/abc263/editorial/4558)  
逆推可以维护后缀和来快速求出累加部分  

```cpp
const int _mod = 998244353;
const int max_n = 2e5+10;

ll arr[max_n],dp[max_n],sum[max_n];

long long fast_pow(long long a,long long b){
    long long res = 1ll;
    for(;b;b >>= 1){
        if(b & 1)
            (res *= a) %= _mod;
        (a *= a) %= _mod;
    }
    return res;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i < n; i++)
        scanf("%lld",&arr[i]);
    for(int i = n-1;i >= 1;i--){
        dp[i] = ((sum[i+1] - sum[i+arr[i]+1]+ 1ll + _mod)%_mod*fast_pow(arr[i],_mod-2) % _mod + 1ll)%_mod;
        sum[i] = (sum[i+1] + dp[i])%_mod;
    }
    printf("%lld\n",dp[1]);
    return 0;
}
```

## f. [Tournament](https://atcoder.jp/contests/abc263/tasks/abc263_f)

```cpp
using ll = long long;

const int max_n = (1<<17)+10;

int c[max_n][17];
ll dp[max_n][17];
int n;

ll dfs(int p,int r){
    if(p >= (1<<n))
        return c[p^(1<<n)][r];  
    if(dp[p][r] != 0)
        return dp[p][r];
    ll res = std::max(dfs(p<<1,r+1)+dfs(p<<1|1,0),dfs(p<<1,0)+dfs(p<<1|1,r+1));
    return dp[p][r] = res;
}

int main(){
    scanf("%d",&n);
    for(int i = 0;i < (1<<n);i++)
        for(int j = 1;j <= n;j++){
            scanf("%d",&c[i][j]);
        }
    printf("%lld\n",dfs(1,0));
    return 0;
}
```