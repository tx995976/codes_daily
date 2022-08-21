//#数学
//@组合数
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdarg>

using ll = long long;

const int _mod = 998244353;
const int max_n = 5e2+10;

ll mod_mul(const ll num, ...){
    std::va_list args;
    va_start(args, num);
}



long long fast_pow(long long a,long long b){
    long long res = 1ll;
    for(;b;b >>= 1){
        if(b & 1)
            (res *= a) %= _mod;
        (a *= a) %= _mod;
    }
    return res;
}

struct rv_fact{
    int range;
    std::vector<ll> fac,inv;
    rv_fact(int n) : fac(n+1),inv(n+1),range(n){table_fact_inv();}

    void table_fact_inv(){
        fac[0] = 1ll;
        for(int i = 1;i < range;i++)
            fac[i] = fac[i-1] * i %_mod;
        inv[range-1] = fast_pow(fac[range-1],_mod-2);
        for(int i = range - 2;i >= 0;i--)
            inv[i] = inv[i+1] * (i+1) % _mod;
    }

    ll C(int n,int k){
        return k <= n ? fac[n]*inv[n-k]%_mod*inv[k]%_mod : 0ll;
    }
};

int main(){
    int n;
    scanf("%d",&n);
    rv_fact c(n*n+1);
    ll r = (n*n)%_mod*c.C(n*n,2*n-1)% _mod*c.fac[n-1]%_mod*c.fac[n-1]%_mod*c.fac[n*n-2*n+1]%_mod;
    printf("%lld\n",(c.fac[n*n]-r+_mod)%_mod);
    return 0;
}