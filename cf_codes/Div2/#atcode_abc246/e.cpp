#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>

const int max_n = 1600;
int a_x,a_y,b_x,b_y,N;
std::vector matix(max_n,std::vector<bool>(max_n,1));
char tmp;

struct edge{
    int dis;
    int x,y;
    bool operator < (const edge &r)const{
        return this->dis < r.dis;
    }
};
std::priority_queue<edge> que;

int dx[] = {1,-1,1,-1};
int dy[] = {1,-1,-1,1};

int main(){
    scanf(" %d",&N);
    scanf(" %d %d %d %d",&a_x,&a_y,&b_x,&b_y);
    for(int i = 1;i <= N;i++)
        for(int j = 1;j <= N;j++){
            scanf(" %c",&tmp);
            matix[i][j] = tmp == '.' ? 0 : 1;
        }
    //dj
    std::vector vis(N+1,std::vector<bool>(N+1,0));
    std::vector dis(N+1,std::vector<int>(N+1,INT32_MAX));
    
    que.push({0,a_x,a_y});
    dis[a_x][a_y] = 0;
    while(!que.empty() && !vis[b_x][b_y]){
        auto it = que.top();
        if(!vis[it.x][it.y]){
            vis[it.x][it.y] = 1;
            for(int i = 0;i < 4;i++){
                int px=it.x,py=it.y;
                px += dx[i],py += dy[i];
                while(!matix[px][py]){
                    if(dis[px][py] > dis[it.x][it.y] + 1){
                        dis[px][py] = dis[it.x][it.y] + 1;
                        que.push({dis[px][py],px,py});
                    }
                    px += dx[i],py += dy[i];
                }
            }
        }
        que.pop();
    }
    printf("%d\n",dis[b_x][b_y]);
    return 0;
}