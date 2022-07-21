#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<bit>

using ll = long long;
const int _mod = 998244353;
int N,L;
int rows[20]={0};
ll ans = 0ll;

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
    scanf(" %d %d",&N,&L);
    std::string tmp;
    for(int i = 1;i <= N;i++){
        std::cin>>tmp;
        for(auto it : tmp)
            rows[i] |= (1<<it-'a');
    }
    for(int i = 1;i < (1<<N);i++){
        int sect = (1<<26)-1;
        for(int j = 0;j < N;j++)
            if(i & (1<<j))
                sect &= rows[j+1];
        int cnt = std::__popcount((unsigned) sect);
        if(std::__popcount((unsigned) i) % 2)
            (ans += fast_pow(cnt,L)) %= _mod;
        else
            (ans += (_mod-fast_pow(cnt,L))) %= _mod;
    }
    printf("%lld\n",ans);
    return 0;
}