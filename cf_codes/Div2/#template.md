## gcd
```cpp
int gcd(int a,int b){
    return b ? gcd(b,a%b) : a;
}
```

## 快速幂
```cpp
long long fast_pow(long long a,long long b){
    long long res = 1ll;
    for(;b;b >>= 1){
        if(b & 1)
            (res *= a) %= _mod;
        (a *= a) %= _mod;
    }
    return res;
}
```