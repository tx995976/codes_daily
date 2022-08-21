<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [ABC263](#abc263)
  - [e. Sugoroku 3](#e-sugoroku-3httpsatcoderjpcontestsabc263tasksabc263_e)
  - [f. Tournament](#f-tournamenthttpsatcoderjpcontestsabc263tasksabc263_f)
  - [g. Erasing Prime Pairs](#g-erasing-prime-pairshttpsatcoderjpcontestsabc263tasksabc263_g)

<!-- /code_chunk_output -->
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

将比赛赛程看作$N+1$层满二叉树  
从顶层(冠军)向下枚举,对左子树赢或右子树赢 取最大值  
维护$dp[p,r]$表示赛程点$p$向上连胜$r$局的最大利益  
通过递归搜索来求出答案  

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

## g. [Erasing Prime Pairs](https://atcoder.jp/contests/abc263/tasks/abc263_g)

如果不考虑$1$的存在,对可操作的两数间加边,将会是一个二分图(偶数选奇数),跑最大流得到$L$  
再将$1$加入,等价于与剩余数配对,跑最大流得$R$ 为$1$与其他剩余数最大匹配数量  
由于可以操作$1+1 = 2$  
那么答案为$ans = (cnt_1 - R)/2 + L + R$


```cpp
using ll = long long;
const int max_p = 2e7+10;
const int inf = 1e9;


struct prime{
    std::vector<bool> flag_prime;
    void prime_list(int range){
        flag_prime.resize(range+1,1);
        flag_prime[1]=0 ;
        for(int i = 2;i <= range;i++){
            if(!flag_prime[i])
                continue;
            for(int j=i+i;j <= range;j+=i)
                flag_prime[j]=0;
        }
    }
};
struct max_flow{
    int n;
    ll max_T;
    struct eg{
        int to;
        ll val;
    };

    std::vector<eg> ed;
    std::vector<std::vector<int>> gh;
    std::vector<int> cur,h;
    max_flow(int in){
        n = in;
        max_T = std::numeric_limits<ll>::max();
        gh.resize(in);
    }

    void add_edge(int f,int t,ll val){
        gh[f].push_back(ed.size());
        ed.push_back((eg){t,val});
        gh[t].push_back(ed.size());
        ed.push_back((eg){f,0});
    }

    bool bfs(int s,int t){
        h.assign(n,-1);
        std::queue<int> que;
        h[s] = 0;
        que.push(s);
        while(!que.empty()){
            int i = que.front();
            que.pop();
            for(int it : gh[i]){
                auto [v,c] = ed[it]; 
                if(c > 0 && h[v] == -1){
                    h[v] = h[i] + 1;
                    if(v == t)
                        return 1;
                    que.push(v);
                }
            }
        }
        return 0;
    }

    ll dfs(int u,int t,ll val){
        if(u == t)
            return val;
        auto r = val;
        for(int &i = cur[u];i < (int)gh[u].size();i++){
            const int j = gh[u][i];
            auto [v,c] = ed[j];
            if(c > 0 && h[v] == h[u] + 1 ){
                auto a = dfs(v,t,std::min(r,c));
                r -= a;
                ed[j].val -= a;
                ed[j^1].val += a;
                if(r == 0)
                    return val;
            }
        }
        return val - r;
    }

    ll mflow(int s,int t){
        ll ans = 0;
        while(bfs(s,t)){
            cur.assign(n,0);
            ans += dfs(s,t,INT64_MAX);
        }
        return ans;
    }
};

std::vector<int> od,c_od,ev,c_ev;

int main(){
    int n;
    prime pr;
    pr.prime_list(max_p);

    scanf("%d", &n);
    std::vector<int> a(n),b(n);
    int c_1 = 0;
    for(int i = 0;i < n;i++){
        scanf("%d %d", &a[i],&b[i]);    
        if(a[i] == 1){
            c_1 = b[i];
            b[i] = 0;
        }
    }
    
    //n起点,n+1终点,依次通过起点->偶数->奇数->终点
    max_flow fm(n+3);
    for(int i = 0;i < n;i++){
        if(a[i] % 2 == 0){
            fm.add_edge(n,i,b[i]); 
            for(int j = 0;j < n;j++)
                if(a[j] % 2 == 1 && pr.flag_prime[a[i]+a[j]])
                    fm.add_edge(i,j,inf); //
        }
        else
            fm.add_edge(i,n+1,b[i]);
    }
    ll L = fm.mflow(n,n+1);
    
    //在搜索图上再加入1
    fm.add_edge(n+2,n+1,c_1);
    for(int i = 0;i < n;i++)
        if(a[i] % 2 == 0 && pr.flag_prime[a[i]+1])
            fm.add_edge(i,n+2,inf);
   
    ll R = L + fm.mflow(n,n+1);

    ll ans = R + (c_1 - (R - L)) / 2;
    printf("%lld\n",ans);
    return 0;
}
```