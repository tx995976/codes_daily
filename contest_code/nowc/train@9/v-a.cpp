#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<vector>

const int max_n = 1e5+10;
std::vector<int> edge[max_n],g_edge[3];
int color[max_n];
int n,m,f,t;
bool flag = 0;

// 
bool g_color(int node,int group = 1){
    color[node] = group;
    g_edge[group].push_back(node);
    
    for(auto i : edge[node]){
        if(!color[i] && g_color(i,3-group))
            return 1;
        if(color[i] == group)
            return 1;
    }
    return 0;
}

int main(){
    scanf(" %d %d",&n,&m);
    for(int i = 1;i <= m;i++){
        scanf(" %d %d",&f,&t);
        edge[f].push_back(t);
        edge[t].push_back(f);
    }
    for(int i = 1;i <= n;i++){  
        if(color[i] == 0){
            if(g_color(i)){
                flag = 1;
                break;
            }
        }
    }
    if(flag)
        printf("-1\n");
    else{
        for(int i = 1;i <= 2;i++){
            printf("%d\n",g_edge[i].size());
            for(auto it :g_edge[i])
                printf("%d ",it);
            printf("\n");
        }
    }
    return 0;
}