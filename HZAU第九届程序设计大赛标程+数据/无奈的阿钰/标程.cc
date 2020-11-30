#include<bits/stdc++.h>
using namespace std;
const int M=100;
int n,k,m,a[M+10],ans;
vector<int> vc[M+10];

struct nd{
    int n,time,cnt;
    nd(int _n,int _time,int _cnt):n(_n),time(_time),cnt(_cnt){}
};

void bfs(int s){
    queue<nd> que;
    que.push(nd(1,0,m));
    while(!que.empty()){
        nd t=que.front();
        que.pop();
        if(t.cnt==0){
            ans=t.time;
            return;
        }
        for(unsigned int i=0;i<vc[t.n].size();++i){
            int v=vc[t.n][i];
            int y=t.cnt;
            if(a[v])y--;
            que.push(nd(v,t.time+t.cnt,y));
        }
    }
}

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&k,&m);
        memset(a,0,sizeof a);
        int t,x,y;
        for(int i=1;i<=m;++i){
            scanf("%d",&t);
            a[t]=1;
        }
        for(int i=0;i<=n;++i)vc[i].clear();
        for(int i=1;i<=k;++i){
            scanf("%d%d",&x,&y);
            vc[x].push_back(y);
        }
        ans=1<<30;
        bfs(1);
        if(ans!=1<<30)printf("%d\n",ans);
        else printf("-1\n");
    }
}
