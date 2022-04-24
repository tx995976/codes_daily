# ABC246

## E.Bishop 2

```cpp
const int max_n = 1505;
int a_x,a_y,b_x,b_y,N;
std::vector matix(max_n,std::vector<bool>(max_n,1));
char tmp;

struct edge{
    int x,y;
};
std::queue<edge> que;
std::vector vis(max_n,std::vector<bool>(max_n,0));
std::vector dis(max_n,std::vector<int>(max_n,INT32_MAX));

int dx[] = {1,-1,1,-1};
int dy[] = {1,-1,-1,1};

int main(){
    scanf(" %d",&N);
    scanf(" %d %d %d %d",&a_x,&a_y,&b_x,&b_y);
    for(int i = 1;i <= N;i++)
        for(int j = 1;j <= N;j++){
            scanf(" %c",&tmp);
            matix[i][j] = tmp == '.' ? 0 : 1;
        }
    //dj
    que.push({a_x,a_y});
    dis[a_x][a_y] = 0;
    while(!que.empty() && !vis[b_x][b_y]){
        auto it = que.front();
        que.pop();
        for(int i = 0;i < 4;i++){
            int px=it.x,py=it.y;
            px += dx[i],py += dy[i];
            while(!matix[px][py]){
                if(!vis[px][py]){
                    dis[px][py] = dis[it.x][it.y] + 1;
                    vis[px][py] = 1;
                    que.push({px,py});
                }
                px += dx[i],py += dy[i];
            }
        }
    }
    printf("%d\n",vis[b_x][b_y] ? dis[b_x][b_y] : -1);
    return 0;
}
```

## F.typewriter

```cpp
using ll = long long;
const int _mod = 998244353;
int N,L;
int rows[20]={0};
ll ans = 0ll;

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
    scanf(" %d %d",&N,&L);
    std::string tmp;
    for(int i = 1;i <= N;i++){
        std::cin>>tmp;
        for(auto it : tmp)
            rows[i] |= (1<<it-'a');
    }
    for(int i = 1;i < (1<<N);i++){
        int sect = (1<<26)-1;
        for(int j = 0;j < N;j++)
            if(i & (1<<j))
                sect &= rows[j+1];
        int cnt = std::__popcount((unsigned) sect);
        if(std::__popcount((unsigned) i) % 2)
            (ans += fast_pow(cnt,L)) %= _mod;
        else
            (ans += (_mod-fast_pow(cnt,L))) %= _mod;
    }
    printf("%lld\n",ans);
    return 0;
}
```
