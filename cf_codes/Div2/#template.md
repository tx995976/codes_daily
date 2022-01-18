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
## 素数筛
```cpp
bool flag_prime[max_n];
int prime[max_n];

int prime_list(int range)
{
    int cnt=0;
    memset(flag_prime,true,sizeof(flag_prime));
    for(int i=2;i<=range;i++)
    {
        if(flag_prime[i])
        prime[++cnt]=i;   // begin:prime[1]
        for(int j=1;j<=cnt;j++){
            if(i*prime[j]>range)
                break;
            flag_prime[i*prime[j]]=0;
            if(i%prime[j]==0)
                break;
        }
    }
    return cnt;
}
```

## 单调队列
```cpp
std::deque<int> num_d;
//基本维护操作
while(!num_d.empty() && num[num_d.back()] > num[i])
            num_d.pop_back();
num_d.push_back(i);

```

## 单调栈
```cpp
std::deque<int> num_cow;
while(!num_cow.empty() && h_cow[i] >= h_cow[num_cow.back()]){
            ans += i - num_cow.back() - 1;
            num_cow.pop_back();
        }
        num_cow.push_back(i);

```

## 并查集
```cpp
//状态压缩
 struct my_union{
        int father[max_n];
        int find(int x){
            if(x != father[x])
                father[x] = find(father[x]);
            return father[x];
        }
        void unionset(int a,int b){
            a = find(a);
            b = find(b);
            father[a] = b;
        }
    };


```