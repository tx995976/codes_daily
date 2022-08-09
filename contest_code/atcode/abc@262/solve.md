# ABC262

## D. [I Hate Non-integer Number](https://atcoder.jp/contests/abc262/tasks/abc262_d)

用$dp_{j,k,l}$表示到第j个数,选择k个以及余数为l的方案数  
得到递推:   
$dp_{j+1,k+1,l+arr[j+1]}$  +=  $dp_{j,k,l}$  
$dp_{j+1,k,l}$ += $dp_{j,k,l}$


```cpp
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
```

## E. [Red and Blue Graph](https://atcoder.jp/contests/abc262/tasks/abc262_e) 

可以知道  
假设红色点的度之和为$S$,$Er$为链接红色点的边数量,$Eb$为链接不同颜色点的边数量,有  
$S = 2Er + Eb$  
$S \equiv Eb $  $(\bmod 2)$  
当 $S$ 为偶数时,可以认为$Eb$为偶数个.  
统计各点的度后,度为奇数 有$o$个时有  
$ans =  \sum C_o^i * C_{n-o}^{k-i} (i = 0;i <= k;i+2)$     
```cpp
using ll = long long;

const int _mod = 998244353;
const int max_n = 2e5+10;

ll fact[max_n] = {0},inv[max_n] = {0};

ll fast_pow(long long a,long long b){
    long long res = 1ll;
    for(;b;b >>= 1){
        if(b & 1)
            (res *= a) %= _mod;
        (a *= a) %= _mod;
    }
    return res;
}


void table_fact_inv(){
    fact[0] = 1ll;
    for(int i = 1;i < max_n;i++)
        fact[i] = fact[i-1] * i %_mod;
    inv[max_n-1] = fast_pow(fact[max_n-1],_mod-2);
    for(int i = max_n - 2;i >= 0;i--)
        inv[i] = inv[i+1] * (i+1) % _mod;
}


ll get_fact(int a,int c){
    return fact[a]*inv[c] % _mod * inv[a-c] % _mod;
}

int main(){
    table_fact_inv();
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    std::vector<int> deg(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        deg[u] += 1;
        deg[v] += 1;
    }

    int od_ver = 0;
    for(int it : deg){
        if(it & 1)
            od_ver++;
    }

    ll ans = 0ll;
    for(int i = 0;i <= k;i += 2){
        if(i <= od_ver && k-i <= n-od_ver){
            (ans += get_fact(od_ver,i) * get_fact(n-od_ver,k-i)) %= _mod;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
```