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
 struct my_union{
        int father[max_n];
        //状态压缩
        int find_zip(int x){
            if(x != father[x])
                father[x] = find(father[x]);
            return father[x];
        }
        //不压缩
        int find(int x){
            x = father[x] == x ? x : find(x);
            return x;
        }
        void unionset(int a,int b){
            a = find(a);
            b = find(b);
            father[a] = b;
        }
    };
```
* 带权并查集
额外存储描述子节点与父节点关系  
例题  
[p2024-食物链](https://www.luogu.com.cn/blog/XTZORZ/solution-p2024)  

## DP
### 01

## 树状数组
```cpp
    const int max_tree = 1e5 + 5;
    int tree[max_tree];

    int lowbit(int x){
        return x & (-x);
    }
    
    void add(int x, int val){
        while(x <= max_tree){
            tree[x] += val;
            x += lowbit(x);
        }
    }

    int query(int x){
        int res = 0;
        while(x > 0){
            res += tree[x];
            x -= lowbit(x);
        }
        return res;
    }

    int query_range(int l, int r){
        return query(r) - query(l - 1);
    }
```

## 线段树
```cpp
     std::vector<int> tree,arr,mark;

    void push_down(int p,int len){
        mark [p << 1] += mark[p];
        mark [p << 1 | 1] += mark[p];
        tree[p << 1] += mark[p] * (len - (len >> 1));
        tree[p << 1 | 1] += mark[p] * (len >> 1);
        mark[p] = 0;
    }

    void build(int l, int r ,int p){
        if(l == r){
            tree[p] = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(l, mid, p << 1);
        build(mid + 1, r,(p << 1) | 1);
        tree[p] = tree[p << 1] + tree[(p << 1) | 1];
        return;
    }

    void update(int l, int r, int d, int p = 1, int tl = 1,int tr = n){
        if(tl >= l && tr <= r){
            tree[p] += d * (tr - tl + 1);
            mark[p] += d;
            return;
        }
        //
        push_down(p,tr - tl + 1);
        int mid = (tl + tr) >> 1;
        if(mid >= l)
            update(l, r, d, p << 1, tl, mid);
        if(mid < r)
            update(l, r, d, (p << 1) | 1, mid + 1, tr);
        tree[p] = tree[p << 1] + tree[(p << 1) | 1];
        return;
    }

    int query(int l, int r, int p = 1, int tl = 1, int tr = n){
        if(tl >= l && tr <= r)
            return tree[p];
        push_down(p,tr - tl + 1);
        int mid = (tl + tr) >> 1;
        int ret = 0;
        if(mid >= l)
            ret += query(l, r, p << 1, tl, mid);
        if(mid < r)
            ret += query(l, r, (p << 1) | 1, mid + 1, tr);
        return ret;
    }


```
    

