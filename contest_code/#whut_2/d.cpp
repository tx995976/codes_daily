#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<string>
#include<vector>

const int max_n = 1e5+10;
int n,m,s,t;

struct pair{
    int to,v;
    bool operator>(const pair &a)const{
        return v>a.v;
    }
};
std::vector<pair>edge[max_n*3];
std::priority_queue<pair,std::vector<pair>,std::greater<pair>> heap;
int type[max_n];


int main(){
    scanf(" %d %d %d %d",&n,&m,&s,&t);
    for(int i = 1; i<= n;i++)
        scanf(" %d",&type[i]);
    for(int i = 1; i<= m;i++){
        int u,v,w;
        scanf(" %d %d %d",&u,&v,&w);
        if(type[v] == 3){
            edge[u].push_back((pair){v,w});
            edge[u+n].push_back((pair){v+n,w});
            edge[u+n*2].push_back((pair){v+n*2,w});
        }
        else if(type[v] == 1){
            edge[u].push_back((pair){v+n,w});
        }
        else if(type[v] == 2){
            edge[u+n].push_back((pair){v+n*2,w});
        }
    }
    std::vector<int>dis(max_n*3,INT32_MAX),vis(max_n*3,0);
    dis[s] = 0;
    heap.push((pair){s,0});
    while(!heap.empty()){
        pair now = heap.top();
        heap.pop();
        if(vis[now.to])
            continue;
        vis[now.to] = 1;
        for(auto &[to,val] : edge[now.to]){
            if(dis[to] > dis[now.to] + val){
                dis[to] = dis[now.to] + val;
                heap.push((pair){to,dis[to]});
            }
        }
    }
    printf("%d\n",dis[t+n*2] == INT32_MAX ? -1 : dis[t+n*2]);
    return 0;
}