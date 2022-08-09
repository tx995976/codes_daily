//#数论
//@卡特兰数
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

using ll = long long;
const int _mod = 998244353;

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
    ll fact = fast_pow(2,n);
    for(int i = n+2;i <= n*2;i++){
        (fact *= i) %= _mod;
    }
    printf("%lld", fact);
    return 0;
}