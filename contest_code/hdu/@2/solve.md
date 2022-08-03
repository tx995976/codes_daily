# hud多校(2)

## c.Copy

修改操作对后续查询影响:  
$x \eqslantless interval(r)$ 无影响  
$x > interval(r)$  相当查询$x - (r-l+1)$  
可以用bitset表示答案需要异或的查询  
对于修改后的查询,对$x > interval(r)$的部分右移$(r-l+1)$ 可以撤销这次修改.  
因此从最后一个操作开始,逐步撤销修改操作来得到答案.


```cpp
const int max_n = 1e5+10;
int arr[max_n],opera[max_n][3];
int n,q;

std::bitset<max_n> xorbit,low,high;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&q);
        for(int i = 1;i <= n;i++)
            scanf("%d",&arr[i]);
        for(int i = 1;i <= q;i++){
            scanf("%d",&opera[i][0]);
            if(opera[i][0] == 1)
                scanf("%d %d",&opera[i][1],&opera[i][2]);
            else
                scanf("%d",&opera[i][1]);
        }

        int ans = 0;
        xorbit = 0;
        for(int i = q;i >= 1;i--){
            if(opera[i][0] == 1){
                int l = opera[i][1],r = opera[i][2];
                low = xorbit & (~std::bitset<max_n>(0) >> (max_n-r-1));
                high = xorbit & (~std::bitset<max_n>(0) << (r+1));
                xorbit = low ^ (high >> (r+1-l));
            }
            else
                xorbit.flip(opera[i][1]);
        }
        for(int i = 1;i <= n;i++)
            if(xorbit[i])
                ans ^= arr[i];
        printf("%d\n",ans);
    }
    return 0;
}
```

## k.DOS Card

在知道一对匹配的值后,我们可以对区间维护:  
区间最大值,区间次大值  
区间最小值,区间次小值  
一对的最大值,两对的最大值  
(一对的值 + 剩下的最大值）的最大值  
(一对的值 - 剩下的最小值）的最大值  
使用线段树能在建树后回答所有询问  

```cpp
using ll = long long;

const int max_n = 1e5+10;
int n,m,arr[max_n];


struct node{
    int len;
    //  bt_max,max,
    //  max_pair1,max_pair2,
    //  psum_max,psub_max,
    //  bt_min,min;
    ll  max[6],min[2];
    node (int i = 0){
        len = i;
        for(ll &it : max)
            it = INT64_MIN;
        for(ll &it : min)
            it = INT64_MAX;
    }
    void u_max (ll a){
        if(a > max[0])
            max[1] = max[0],max[0] = a;
        else if(a > max[1])
            max[1] = a;
    }
    void u_min (ll a){
        if(a < min[0])
            min[1] = min[0],min[0] = a;
        else if(a < min[1])
            min[1] = a;
    }
    node operator + (const node &r)const{
        if(len == 0)
            return r;
        if(r.len == 0)
            return *this;

        node temp(len + r.len);

        for(int i = 0; i < 2;i++){
            temp.u_max(max[i]);
            temp.u_min(min[i]);
            temp.u_max(r.max[i]);
            temp.u_min(r.min[i]);
        }

        temp.max[2] = std::max(temp.max[2],max[2]);
        temp.max[2] = std::max(temp.max[2],r.max[2]);
        temp.max[2] = std::max(temp.max[2],max[0]-r.min[0]);

        temp.max[3] = std::max(temp.max[3],max[3]);
        temp.max[3] = std::max(temp.max[3],r.max[3]);
        temp.max[3] = std::max(temp.max[3],max[2]+r.max[2]);
        temp.max[3] = std::max(temp.max[3],max[0]+max[1]-r.min[0]-r.min[1]);
        temp.max[3] = std::max(temp.max[3],max[4]-r.min[0]);
        temp.max[3] = std::max(temp.max[3],max[0]+r.max[4]);

        temp.max[4] = std::max(temp.max[4],max[4]);
        temp.max[4] = std::max(temp.max[4],r.max[4]);
        temp.max[4] = std::max(temp.max[4],max[2]+r.max[0]);
        temp.max[4] = std::max(temp.max[4],r.max[2]+max[0]);
        if(r.len >= 2)
            temp.max[4] = std::max(temp.max[4],max[0]-r.min[0]+r.max[0]);
        if(len >= 2)
            temp.max[4] = std::max(temp.max[4],max[0]-r.min[0]+max[1]);

        temp.max[5] = std::max(temp.max[5],max[5]);
        temp.max[5] = std::max(temp.max[5],r.max[5]);
        temp.max[5] = std::max(temp.max[5],max[2]-r.min[0]);
        temp.max[5] = std::max(temp.max[5],r.max[2]-min[0]);
        if(r.len >= 2)
            temp.max[5] = std::max(temp.max[5],max[0]-r.min[0]-r.min[1]);
        if(len >= 2)
            temp.max[5] = std::max(temp.max[5],max[0]-r.min[0]-min[0]);
        return temp;
    }
};

node tree[max_n << 2];

void build(int l = 1,int r = n,int tp = 1){
    if(l == r){
        tree[tp] = node(1);
        tree[tp].max[0] = tree[tp].min[0] = 1ll*arr[l]*arr[l];
        return;
    }
    int mid = (l+r) >> 1;
    build(l,mid,tp<<1);
    build(mid+1,r,(tp<<1)|1);
    tree[tp] = tree[tp<<1]+tree[tp<<1|1];
}

node query(int l,int r,int tl = 1,int tr = n,int tp = 1){
    if(tl > r || tr < l)
        return node(0);
    if(tl >= l && tr <= r)
        return tree[tp];
    int mid = l + r >> 1;
    return query(l,r,tl,mid,tp<<1)+query(l,r,mid+1,tr,tp<<1|1);
}


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        for(int i = 1; i <= n; i++)
            scanf("%d",&arr[i]);
        build();
        int ql,qr;
        for(int i = 1;i <= m;i++){
            scanf("%d %d",&ql,&qr);
            printf("%lld\n",query(ql,qr).max[3]);
        }
    }
    return 0;
}
```

## l.Luxury cruise ship

先求出一定lim范围内的最少天数  
范围内的询问可直接回答  
超出则通过减最大金币将数值缩小至范围内再回答

```cpp
using ll = long long;

const int lim = 365*4;

std::vector<ll> dp(lim+1,INT64_MAX-1ll);
ll coin[] = {7,31,365};

int main(){
    int t;
    scanf("%d",&t);
    dp[7] = dp[31] = dp[365] = 1ll;
    for(int i = 8;i <= lim;i++){
        for(ll it : coin){
            if(i > it)
                dp[i] = std::min(dp[i],dp[i-it]+1ll);
        }
    }
    while(t--){
        ll n;
        scanf("%lld",&n);
        if(n > lim){
            ll cnt = (n-lim)/365+1ll,   mod = n-cnt*365;
            printf("%lld\n",dp[mod] == INT64_MAX - 1ll ? -1ll : dp[mod]+cnt);
        }
        else
            printf("%lld\n",dp[n] == INT64_MAX - 1ll ? -1ll : dp[n]);
    }
    return 0;
}
```