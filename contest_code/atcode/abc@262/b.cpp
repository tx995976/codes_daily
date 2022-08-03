//#图论
//
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>
#include<bitset>

std::bitset<110> ver[110];
struct eg{int u,v;};
std::vector<eg> edge;


int main(){
    int n,m,u,v;
    scanf("%d %d",&n,&m);    
    for(int i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        edge.push_back((eg){u,v});
        ver[u].set(v);
        ver[v].set(u);
    }
    int ans = 0;
    for(auto &[u,v] : edge){
        ans += (ver[u]&ver[v]).count();
        ver[u].reset(v);
        ver[v].reset(u);
    }
    printf("%d\n",ans);
    return 0;
}