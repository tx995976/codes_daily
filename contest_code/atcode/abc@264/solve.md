# abc@264

## E. [Blackout 2](https://atcoder.jp/contests/abc264/tasks/abc264_e)
给定一定边,并在去掉一部分边,求出每次去除时与电厂相连的城市数量  
由于操作数已知,那么可以反向操作,将去边转换为加边  
将所有电厂看作一个点,通过并查集来完成计数  

```cpp
const int max_n = 5e5+10;
int N,M,E,Q;

struct funion{
        std::vector<int> father,size;
        funion(int n) : father(n),size(n){
            for(int i = 0;i < n;i++){
                father[i] = i;
                size[i] = 1;
            }
        }
        int find_zip(int x){
            if(x != father[x])
                father[x] = find_zip(father[x]);
            return father[x];
        }
        void unionset(int a,int b){
            a = find_zip(a);
            b = find_zip(b);
            if(a != b){
                father[a] = b;
                size[b] += size[a];
                size[a] = 0;
            }
        }
    };

bool adg[max_n];
struct ed{int u,v;};
std::vector<ed> edge;

int main(){
    scanf("%d %d %d",&N,&M,&E);
    int u,v;

    for(int i = 1;i <= E;i++){
        scanf("%d %d",&u,&v);
        u = u > N ? N+1 : u;
        v = v > N ? N+1 : v;
        edge.push_back(ed{u,v});
    }

    scanf("%d",&Q);
    std::vector<int> q(Q),ans(Q+1);
    for(int &i : q){
        scanf("%d",&i);
        //printf("ed:%d\n",i);
        adg[i] = 1;
    }
    funion tree(max_n);
    for(int i = 1;i <= E;i++){
        if(adg[i])
            continue;
        auto [u,v] = edge[i-1];
        if(tree.find_zip(u) == N+1)
            std::swap(u,v);
        tree.unionset(u,v);
    }

    ans[Q] = tree.size[N+1]-1;
    for(int i = Q-1;i > 0;i--){
        auto [u,v] = edge[(q[i]-1)];
        //printf("get: %d %d\n",u,v);
        if(tree.find_zip(u) == N+1)
            std::swap(u,v);
        tree.unionset(u,v);
        ans[i] = tree.size[N+1]-1;
    }
    for(int i = 1;i <= Q;i++)
        printf("%d\n",ans[i]);

    return 0;
}
```

## F. [Monochromatic Path](https://atcoder.jp/contests/abc264/tasks/abc264_f)

先考虑通过白色路径到达终点  
令$dp[x][y][d][l]$  表示在点$[x,y]$,下一步方向$d$(下\右),所面对$l$`行(右)\列(下)`是否反转 的最小花费  
那么从该点方向$d$得到下个点$[tx,ty]$,得到令该点成为白色的成本$val =$ 需要反转的相应行\列的花费,$d$朝右反转列,朝下反转行     
能得到递推  
$dp[tx][ty][td][tl] = min(dp[x][y][d][l]+val,dp[tx][ty][td][tl])$  
其中$td,d$同向时$tl = l$,不同向时$tl$为相应的(行\列)是否需要反转  
那么答案为$min(dp[h][w][0...1][0...1])$  
将所有颜色反转再求一次黑色取最下即可  
```cpp
const int max_n = 2e3+10;
using ll = long long;

int h,w;
char gh[max_n][max_n];
ll r[max_n],c[max_n];
ll dp[max_n][max_n][2][2]; // x,y,dirc,
int dh[] = {1,0},dw[] = {0,1};



int main(){
    scanf("%d %d",&h,&w);
    for(int i = 1;i <= h;i++)
        scanf("%lld",&r[i]);

    for(int i = 1;i <= w;i++)
        scanf("%lld",&c[i]);

    for(int i = 1;i <= h;i++)
        for(int j = 1;j <= w;j++){
            scanf(" %c",&gh[i][j]);
            gh[i][j] -= '0';
        }

    auto f = [&](){
        memset(dp,0x5f,sizeof(dp));

        for(int i = 0;i <= 1;i++){
            int j = (gh[1][1] ^ i);
            dp[1][1][0][j] = i*r[1] + j*c[1];
            dp[1][1][1][i] = i*r[1] + j*c[1];
        }

        for(int i = 1;i <= h;i++)
            for(int j = 1;j <= w;j++)
                for(int d = 0;d <= 1;d++)
                    for(int l = 0;l <= 1;l++){
                        int ti = i + dh[d],tj = j + dw[d];
                        if(ti > h || tj > w)
                            continue;
                        //需要反转?
                        int bfilp = gh[ti][tj] ^ l, val = 0;
                        if(d == 0) 
                            val = r[ti]*bfilp;
                        else
                            val = c[tj]*bfilp;

                        for(int td = 0;td <= 1;td++){
                            int tl = l;
                            if(d != td)
                                tl = bfilp;
                            //printf("be :%lld %lld\n", dp[ti][tj][td][tl],dp[i][j][d][l] + val);
                            dp[ti][tj][td][tl] = std::min(dp[ti][tj][td][tl],dp[i][j][d][l] + val);
                            //printf("af: %lld \n", dp[ti][tj][td][tl]);
                        }
                    }
        ll res = INT64_MAX-1;
        for(int i = 0;i <= 1;i++)
            for(int j = 0;j <= 1;j++)
                res = std::min(res,dp[h][w][i][j]);
        return res;
    };
    
    ll ans = f();
    for(int i = 1;i <= h;i++)
        for(int j = 1;j <= w;j++)
            gh[i][j] ^= 1;

    ans = std::min(ans,f());
    printf("%lld\n",ans);
    return 0;
}
```

