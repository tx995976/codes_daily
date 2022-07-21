#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<queue>

const int max_n = 1e5+10;
int ver[max_n];
int N,Q;
int t1,t2;
std::vector<int> edge[max_n],nums[max_n];

struct edge{
    int from,to;
};

void dfs(int v,int father){
    nums[v].push_back(ver[v]);
    for(auto it : edge[v]){
        if(it == father)
            continue;
        dfs(it,v);
        for(auto i : nums[it])
            nums[v].push_back(i);
    }
    std::sort(nums[v].begin(),nums[v].end(),std::greater<int>());
    while(nums[v].size() > 20)
        nums[v].pop_back();
}

int main(){
    scanf(" %d %d",&N,&Q);
    for(int i = 1;i <= N;i++)
        scanf(" %d",&ver[i]);
    for(int i = 1;i <= N-1;i++){
        scanf(" %d %d",&t1,&t2);
        edge[t1].push_back(t2);
        edge[t2].push_back(t1);
    }
    dfs(1,0);
    while(Q--){
        scanf(" %d %d",&t1,&t2);
        printf("%d\n",nums[t1][t2-1]);
    }
    return 0;
}