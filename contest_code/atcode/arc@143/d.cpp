//#
//@
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

const int max_n = 2e5+10;

int n,m;
int a[max_n],b[max_n];
bool vis[max_n],ans[max_n];
struct ed{int u,v;};
std::vector<ed> edge[max_n];

void dfs(int s){
    vis[s] = 1;
    for(auto [t,i] : edge[s]){
        if(!vis[t])
            dfs(t);
        else
            ans[i] = (s == a[i]);
    }

}

int main(){
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= m;i++)
        scanf("%d",&a[i]);
    for(int i = 1; i <= m;i++)
        scanf("%d",&b[i]);
    for(int i = 1; i <= m;i++){
        edge[a[i]].push_back((ed){b[i],i});
        edge[b[i]].push_back((ed){a[i],i});
    }
    for(int i = 1; i <= n;i++)  
        if(!vis[i])
            dfs(i);
    for(int i = 1; i <= m;i++)  
        printf("%d",ans[i] ? 1 : 0);
    printf("\n");
    return 0;
}