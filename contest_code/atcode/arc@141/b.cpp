//#
//@
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

using ll = long long;;

const int _mod = 998244353;

template <typename T>
struct mint{
    T val;
    mint(T _val) : val(_val%_mod){}
    mint(){}
    T*  operator &(){return &val;}
    T&  operator *(){return val;}
    void  operator =(const T &r){val = r%_mod;}
    mint operator +(const mint &r){return mint(val+r.val);}
    mint operator *(const mint &r){return mint(val*r.val);}
    mint operator -(const mint &r){return mint(val+_mod-r.val);}
    void operator +=(const mint &r){(val+r.val)%_mod;}
    void operator -=(const mint &r){(val+_mod-r.val) % _mod;}
    void operator *=(const mint &r){(val*r.val) % _mod;}
};

using mll = mint<ll>;

mll dp[65]; //->dp[n][m] 
ll m,n;

int main(){
    scanf("%lld %lld",&n,&m);
    dp[0] = 1ll;
    int b = 1;
    for(ll i = 1ll;i <= m;b+=1,i<<=1){
        //printf("%lld\n",i);
        mll t(std::min(m,i*2-1)-i+1ll); //cnt_digit[b]
        for(int j = b;j >= 0;j--)
            dp[j] += dp[j-1]*t;
    }
    printf("%lld\n",n>b ? 0ll : dp[n]);
    return 0;
}