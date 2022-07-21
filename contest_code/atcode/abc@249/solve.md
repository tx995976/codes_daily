# ABC_249

## D.Index Trio

要寻找符合条件的i,j,k
记录 Ai 对应数字的个数(cnt[1~2e5])
Ai = Aj * Ak
所以我们可以枚举`Aj`,那么可以确定`Ak`的范围(`max_n` / `Aj`)
所以 ans += cnt[Aj] * cnt[AK] * cnt[Aj*Ak]

```cpp
const int max_n = 2e5+10;
int N,tmp;
std::vector<long long> cnt(max_n,0ll);
long long ans = 0ll;
int lim;

int main(){
    scanf(" %d",&N);
    for(int i = 1;i <= N;i++){
        scanf(" %d",&tmp);
        cnt[tmp] += 1;
    }
    for(int i = 1;i <= max_n;i++){
        if(cnt[i])
            for(int j = 1;j <= max_n/i;j++){
                ans += cnt[i]*cnt[j]*cnt[i*j];
            }
    }
    printf("%lld\n",ans);
    return 0;
}
```

## E.RLE




```cpp
using ll = long long;
const int max_n = 4e3+10;
int N,_mod;
ll dp[max_n][max_n];
ll sum[max_n][max_n];
ll oct_dit[] = {1,10,100,1000,10000};


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
    scanf(" %d %d",&N,&_mod);

    dp[0][0] = fast_pow(25,_mod-2)* 26ll % _mod;
    for(int i = 1;i <= N;i++)
        sum[0][i] = dp[0][0];

    for(int i = 1;i <= N;i++)
        for(int j = 1;j <= N;j++){
            for(int k = 1;k <= 4;k++){
                if(i-k-1 < 0) 
                    continue;
                ll x = std::max(j-oct_dit[k-1]+1,0ll),y = std::max(j-oct_dit[k]+1,0ll);
                (dp[i][j] += (sum[i-k-1][x]-sum[i-k-1][y]+_mod)*25) %= _mod;
            }
            (sum[i][j+1] = sum[i][j]+dp[i][j]) %= _mod;
        }

    ll ans = 0ll;
    for(int i = 1;i < N;i++)
        (ans += dp[i][N]) %= _mod;
    printf("%lld\n",ans);
    return 0;
}
```
