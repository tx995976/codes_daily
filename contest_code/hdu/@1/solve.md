# hdu多校(1)

## b.Dragon slayer

枚举墙的所有消除情况,当能走通时更新答案.  
同时分开处理横墙与竖墙,暴力搜索即可  

```cpp
int pan[20][20],hw[20][20],lw[20][20];
int hx,hy,dx,dy,n,m,k,x1,y1,x2,y2;
int ans;
struct p {int x1,y1,x2,y2;} wp[20];

int bitcnt(int x){
    int cnt = 0;
    while(x){
        if(x & 1) 
            cnt++;
        x >>= 1;
    }
    return cnt;
}

bool dfs(int x,int y){
    pan[x][y] = 1;
    if(x == dx && y == dy){
        return 1;
    }
    bool flag = 0;
    if(x > 0 && hw[x][y] == 0 && pan[x-1][y] == 0)
        flag |= dfs(x-1,y);
    if(x < n-1 && hw[x+1][y] == 0 && pan[x+1][y] == 0)
        flag |= dfs(x+1,y);
    if(y > 0 && lw[x][y] == 0 && pan[x][y-1] == 0)
        flag |= dfs(x,y-1);
    if(y < m-1 && lw[x][y+1] == 0 && pan[x][y+1] == 0)
        flag |= dfs(x,y+1);
    return flag;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ans = INT32_MAX;
        scanf("%d %d %d",&n,&m,&k);
        scanf("%d %d %d %d",&hx,&hy,&dx,&dy);

        for(int i = 0;i < k;i++)
            scanf("%d %d %d %d",&wp[i].x1,&wp[i].y1,&wp[i].x2,&wp[i].y2);

        for(int i = 0;i <(1<<k);i++){
            memset(pan,0,sizeof(pan));
            memset(hw,0,sizeof(hw));
            memset(lw,0,sizeof(lw));
            for(int j = 0;j < k;j++){
                if((i & (1 << j)) == 0)
                    if(wp[j].x1 == wp[j].x2){
                        int s = std::min(wp[j].y1,wp[j].y2);
                        for(s;s < std::max(wp[j].y1,wp[j].y2);s++)
                            hw[wp[j].x1][s] = 1;
                    }
                    else{
                        int s = std::min(wp[j].x1,wp[j].x2);
                        for(s;s < std::max(wp[j].x1,wp[j].x2);s++)
                            lw[s][wp[j].y1] = 1;
                    }
            }
            if(dfs(hx,hy)){
                ans = std::min(ans,bitcnt(i));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
```

## c. Backpack

$f_{i,j,k}$表示前i个物品,异或和为j,体积为k的方案是否可行  
因此得到递推公式: $f_{i,j,k} = f_{i-1,j,k} \vee f_{i-1,j \oplus v_i,k-w_i} $  
体积部分可使用std::bitset压位  
也就是 $f_{i,j} = f_{i-1,j \oplus v_i} \ll w_i  \vee f_{i-1,j} $ 

```cpp
int T,ans;
std::bitset<1025> t1[1025],t2[1025];

int main(){
    scanf("%d",&T);
    int n,m,v,w;
    while(T--){
        scanf("%d %d",&n,&m);
        for(int i = 0;i < 1024;i++)
            t1[i].reset();
        t1[0][0] = 1;

        for(int i = 1;i <= n;i++){
            scanf("%d %d",&v,&w);
            for(int j = 0;j < 1024;j++){
                t2[j] = t1[j];
                t2[j] <<= v;
            }
            for(int j = 0;j < 1024;j++){
                t1[j] |=  t2[j^w];
            }
        }
            
        ans = -1;
        for(int i = 1023;i >= 0 ;i--)
            if(t1[i][m]){
                ans = i;
                break;
            }
        printf("%d\n",ans);
    }
    return 0;
}
```


## d.ball

求出所有点距离,并升序排序,用bitset来存储两点间距离出现情况  
从小遍历距离,为素数时,该距离两点的bitset中,对同一点距离出现情况不同时  
表示到该点有一条 小于或等于 和 大于或等于 的边  即为满足条件的一个情况  
反映到bitset即为异或  

```cpp
const int max_n = 2010;
int n,m;

struct {int x,y;} pos[max_n];
struct di {
    int dis,a,b;
    bool operator < (const di &r){
        return dis < r.dis;
    }
} A[max_n*max_n];

std::bitset<max_n> pan[max_n];

using prime_ruler = temp::prime_ruler;

int main(){
    prime_ruler prime;
    prime.prime_list(2e5+10);

    int t;
    scanf("%d",&t);
    while(t--){
        long long ans = 0ll;
        scanf("%d %d",&n,&m);
        for(int i = 1;i <= n;i++){
            pan[i].reset();
            scanf("%d %d",&pos[i].x,&pos[i].y);
        }   
        int cnt = 0;
        for(int i = 1;i <= n;i++)
            for(int j = i+1;j <= n;j++){
                A[++cnt] = (di){std::abs(pos[i].x-pos[j].x)+std::abs(pos[i].y-pos[j].y),i,j};
            }
        std::sort(A+1,A+1+cnt);
        for(int i = 1;i <= cnt;i++){
            if(!prime.flag_prime[A[i].dis])
                ans += (pan[A[i].a]^pan[A[i].b]).count();
            pan[A[i].a][A[i].b] = 1;
            pan[A[i].b][A[i].a] = 1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

```


## i.Laser

镭射呈"米"字形  
所有点在一条线上显然为可行  
一般情况,假设第一个点在竖线上,通过另一个不在该线上的一点,假设为横线,斜线上时,能得到3个镭射中心点  
依次检查这三个点是否可行  
同样假设第一个点在横线,斜线上时,有另外3种情况,全部检查是否可行,共12个点.  

```cpp
const int max_n = 5e5+10;

int x[max_n],y[max_n],xa[max_n],ya[max_n];
int t,n;

bool check_line(int xi,int yi){
    for(int i = 1;i <= n;i++){
        if(xi == x[i] || yi == y[i] || xi-x[i] == yi-y[i] || xi+yi == x[i]+y[i])
            continue;
        else
          return 0;
    }
    return 1;
}

bool check(){
    bool flag = 1;
    for(int i = 2;i <= n;i++){
        if(x[i] == x[1])
            continue;
        flag = 0;
        if(check_line(x[1],y[i]))
            return 1;
        if(check_line(x[1],y[i] + (x[i]-x[1])))
            return 1;
        if(check_line(x[1],y[i] - (x[i]-x[1])))
            return 1;
        
        break;
    }
    if(flag)
        return 1;
    return 0;
}

int main(){
    scanf("%d",&t);
    while(t--){
        bool flag = 0;
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
            scanf("%d %d",&xa[i],&ya[i]);
        for(int i = 1;i <= n;i++)
            x[i] = xa[i],y[i] = ya[i];
        flag = check();
        if(!flag){
            for(int i = 1;i <= n;i++)
                x[i] = ya[i],y[i] = xa[i];
            flag = check();
        }
        if(!flag){
            for(int i = 1;i <= n;i++)
                x[i] = xa[i] + ya[i],y[i] = xa[i] - ya[i];
            flag = check();
        }
        if(!flag){
            for(int i = 1;i <= n;i++)
                x[i] = xa[i] - ya[i],y[i] = xa[i] + ya[i];
            flag = check();
        }
        printf("%s\n",flag ? "YES" : "NO");
    }
    return 0;
}
```