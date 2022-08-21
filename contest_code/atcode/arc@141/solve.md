# arc@141

## b.[Increasing Prefix XOR](https://atcoder.jp/contests/arc141/tasks/arc141_b)

从$1...m$组成递增序列$P = (A_1...A_n)$  
满足$B = (B_1...B_n) B_i = A_1 \oplus A_2 \oplus ... A_i$,$B$也为递增序列  
从二进制来看,$B_1...B_n$的最高位呈递增时是满足条件的  
当$n > 最高位数(m)$时,显然没有答案  
那么有$DP[i]$表示序列长度为$i$,最高位为$i$的选法  
$DP[i] = DP[i] + DP[i-1]*t$,其中$t$为最高位为$i$的数字数量  
答案为$DP[n]$

```cpp
using ll = long long;;

const int _mod = 998244353;

template <typename T>
struct mint{
    T val;
    mint(T _val) : val(_val%_mod){}
    mint(){}
    T*  operator &(){return &val;}
    T&  operator *(){return val;}
    mint operator +(const mint &r){return mint(val+r.val);}
    mint operator *(const mint &r){return mint(val*r.val);}
    mint operator -(const mint &r){return mint(val+_mod-r.val);}
    void operator =(const T &r){val = r%_mod;}
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
```
