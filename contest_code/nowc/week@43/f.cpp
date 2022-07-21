#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<vector>

const int max_n = 2e5+10;

std::vector<int> edge[max_n];

int color[max_n];
int pos_[max_n];
int n,m,k,flag = 0;

void graph_judge(int node,int group){
    if(flag)
        return;
    color[node] = group;
    for(int i = 0;i < edge[node].size();i++){
        int node2 = edge[node][i];
        if(color[node2] != 0 && color[node2] == group){   //非二分图
            flag = 1;
            return;
        }
        if(color[node2])
            continue;
        graph_judge(node2,3 - group);
    }
}

int main(){
    int node1,node2;
    scanf(" %d %d %d",&n,&m,&k);
    for(int i = 1;i <= m;i++){
        scanf(" %d %d",&node1,&node2);
        edge[node1].push_back(node2);
        edge[node2].push_back(node1);
    }
    for(int i = 1;i <= k;i++)
        scanf(" %d",&pos_[i]);
    graph_judge(1,1);
    if(flag)
        printf("YES\n");
    else{
        int group = color[pos_[1]];
        for(int i = 2;i <= k;i++){
            if(color[pos_[i]] != group){
                printf("NO\n");
                return 0;
            }
        }
        printf("YES\n");
    }
    return 0;
}