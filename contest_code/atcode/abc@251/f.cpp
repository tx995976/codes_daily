#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>
#include<cstring>

const int max_n = 2e5+10;
std::vector<std::vector<int>> edge;
bool vis[max_n];

int n,m;

void dfs(int nd){
    vis[nd] = 1;
    for(auto it : edge[nd]){
        if(!vis[it]){
            printf("%d %d\n",nd,it);
            dfs(it);
        }
    }
}

void bfs(){
    std::deque<int> q;
    vis[1] = 1;
    q.push_back(1);
    while(!q.empty()){
        int pd = q.front();
        q.pop_front();
        for(auto it : edge[pd]){
           if(!vis[it]){
               printf("%d %d\n",pd,it);
               q.push_back(it);
               vis[it] = 1;
           }
        }
    }
}

int main(){
    scanf(" %d %d", &n, &m);
    edge.resize(n+1,std::vector<int>());
    for(int i = 0;i < m;i++){
        int u,v;
        scanf(" %d %d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    std::memset(vis,0,sizeof(vis));
    dfs(1);
    std::memset(vis,0,sizeof(vis));
    bfs();
    return 0;
}