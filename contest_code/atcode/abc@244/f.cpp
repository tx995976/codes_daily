#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<vector>

const int max_n = 20;
std::vector<int> edge[max_n];
std::deque<std::pair<int,int>> que;
int dis[1<<17][18];
int n,m;
long long ans = 0;

int main(){
    scanf(" %d %d",&n,&m);
    int f,t;
    for(int i = 1;i <= m;i++){
        scanf(" %d %d",&f,&t);
        edge[f].push_back(t);
        edge[t].push_back(f);
    }
    
    int N = 1<<n;
    for(int i = 1;i < N;i++)
        for(int j = 1;j <= n;j++)
            dis[i][j] = INT32_MAX;
    for(int i = 0;i < n;i++){
        dis[1<<i][i+1] = 1;
        que.push_back({1<<i,i+1});
    }

    while(!que.empty()){
        int s = que.front().first, p = que.front().second;
        que.pop_front();
        for(auto eg : edge[p]){
            int p_s = s ^ (1<<(eg-1)); // 将eg加入后的S数值
            //已有,应为更小解
            if(dis[p_s][eg] < INT32_MAX)
                continue;
            dis[p_s][eg] = dis[s][p] + 1;
            que.push_back({p_s,eg});
        }
    }

    for(int i = 1;i < N;i++){
        int Val_s = INT32_MAX;
         for(int j = 1;j <= n;j++)
            Val_s = std::min(Val_s,dis[i][j]);
        ans += (long long)Val_s;
    }
    printf("%lld\n",ans);
    return 0;
}