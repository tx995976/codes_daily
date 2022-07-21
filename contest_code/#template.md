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
## 二分
```cpp
    while(L<=R)
    {
        int mid=(L+R)>>1;
        if(judge(mid)) 
        {
            ans=mid;
            L=mid+1;
        }
        else R=mid-1;
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
## DP
### 01

### 数位dp
```cpp
ll dfs(int pos,int pre,int st,……,int lead,int limit)//记搜
{
    if(pos>len) return st;//剪枝
    if((dp[pos][pre][st]……[……]!=-1&&(!limit)&&(!lead))) return dp[pos][pre][st]……[……];//记录当前值
    ll ret=0;//暂时记录当前方案数
    int res=limit ? a[len-pos+1] : 9;//res当前位能取到的最大值
    for(int i=0;i<=res;i++)
    {
        //有前导0并且当前位也是前导0
        if((!i)&&lead) ret+=dfs(……,……,……,i==res&&limit);
        //有前导0但当前位不是前导0，当前位就是最高位
        else if(i&&lead) ret+=dfs(……,……,……,i==res&&limit); 
        else if(根据题意而定的判断) ret+=dfs(……,……,……,i==res&&limit);
    }
    if(!limit&&!lead) dp[pos][pre][st]……[……]=ret;//当前状态方案数记录
    return ret;
}
ll part(ll x)//把数按位拆分
{
    len=0;
    while(x) a[++len]=x%10,x/=10;
    memset(dp,-1,sizeof dp);//初始化-1（因为有可能某些情况下的方案数是0）
    return dfs(……,……,……,……);//进入记搜
}
```
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
    void push_down(int p,int tl,int tr){
        mark [p << 1] += mark[p];
        mark [p << 1 | 1] += mark[p];
        ll mid = (tl + tr) >> 1;
        tree[p << 1] +=  1ll * mark[p] * (mid - tl + 1);
        tree[p << 1 | 1] += 1ll * mark[p] * (tr - mid);
        mark[p] = 0;
        return; 
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

    void update(int l, int r, int d, int p = 1, int tl = 1,int tr = N){
        if(l > tr || r < tl) 
            return;
        if(tl >= l && tr <= r){
            tree[p] += 1ll * d * (tr - tl + 1);
            mark[p] += d;   
            return;
        }
        if(mark[p])
            push_down(p,tl,tr);
        int mid = (tl + tr) >> 1;
        if(mid >= l)
            update(l, r, d, p << 1, tl, mid);
        if(mid < r)
            update(l, r, d, (p << 1) | 1, mid + 1, tr);
        tree[p] = tree[p << 1] + tree[(p << 1) | 1];
        return;
    }

    ll query(int l, int r, int p = 1, int tl = 1, int tr = N){
        if(l > tr || r < tl)
            return 0;
        if(tl >= l && tr <= r)
            return tree[p];
        if(mark[p])
            push_down(p,tl,tr);
        int mid = (tl + tr) >> 1;
        ll ret = 0;
        if(mid >= l)
            ret += query(l, r, p << 1, tl, mid);
        if(mid < r)
            ret += query(l, r, (p << 1) | 1, mid + 1, tr);
        return ret;
    }
```