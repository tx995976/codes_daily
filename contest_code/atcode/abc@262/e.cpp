//#图论
//@组合数
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

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