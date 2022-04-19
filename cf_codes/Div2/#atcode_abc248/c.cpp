#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>

const int _mod = 998244353;
int N,M,K;
long long ans;

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
    scanf(" %d %d %d",&N,&M,&K);
    

    
    printf("%lld\n",ans);
    return 0;
}