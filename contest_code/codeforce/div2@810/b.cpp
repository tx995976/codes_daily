//#图论
//@
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>
#include<cstring>

const int max_n = 1e5+10;
struct {int u,v;} edge[max_n];
int deg[max_n],a[max_n];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        memset(deg,0,sizeof(deg));
        scanf("%d %d",&n,&m);
        for(int i = 1; i <= n; i++)
            scanf("%d",&a[i]);
        for(int i = 1; i <= m; i++){
            scanf("%d %d",&edge[i].u,&edge[i].v);
            deg[edge[i].u] += 1;
            deg[edge[i].v] += 1;
        }
        int ans = INT32_MAX;
        if(m & 1){
            for(int i = 1; i <= n;i++)
                if(deg[i]&1)
                    ans = std::min(ans,a[i]);
            for(int i = 1; i <= m;i++)
                if(deg[edge[i].u]%2 == 0 && deg[edge[i].v]%2 == 0)
                    ans = std::min(ans,a[edge[i].u]+a[edge[i].v]);
        }
        else
            ans = 0;
        printf("%d\n",ans);
    }
    return 0;
}