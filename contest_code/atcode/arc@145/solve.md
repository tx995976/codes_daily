# ARC145 

## b. [AB Game](https://atcoder.jp/contests/arc145/tasks/arc145_b)

Ailce 先手且可以拿取$a$的倍数的石头,相当于 $f_{k+1} = f_{k} \bmod a$  
那么当$n \eqslantgtr a$,$a \eqslantless b$时,显然必胜  
当$a > b , n \eqslantgtr a$时, $n \bmod a < b$是必胜  

```cpp
using ll = long long;
ll N,a,b,ans;


int main(){
    scanf(" %lld %lld %lld",&N,&a,&b);
    ans = 0ll;
    if(a <= b){
        if(N > (a-1ll))
            ans = (N-(a-1ll));
    }
    else{
        ll cnt = N/a-1ll,mod = N%a;
        if(cnt >= 0)
            ans += cnt*b + (mod >= b-1ll ? b : mod+1ll);
    }
    printf("%lld\n",ans);
    return 0;
}
```

## c. [Split and Maximize](https://atcoder.jp/contests/arc145/tasks/arc145_c)

显然$M$取最大的情况是$\sum_{i=1}^{n} N_{2i-1}N_{2i}$  
对于序列$p$,将$(N_{2i-1},N_{2i})$看作一对,那么有$N!2^N$种方案排列  
但$A,B$子序列不一定连续,即看作出栈方式分组,有$\dfrac{C_{2n}^n}{n+1}$ [^卡特兰数] 种方式  
即总共$2^N\dfrac{(2N)!}{(N+1)!}$ 种方案  



```cpp
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
```



[^卡特兰数]: https://oi-wiki.org/math/combinatorics/catalan/