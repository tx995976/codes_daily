#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>

const int max_n = 1505;
int a_x,a_y,b_x,b_y,N;
std::vector matix(max_n,std::vector<bool>(max_n,1));
char tmp;

struct edge{
    int x,y;
};
std::queue<edge> que;
std::vector vis(max_n,std::vector<bool>(max_n,0));
std::vector dis(max_n,std::vector<int>(max_n,INT32_MAX));

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
    que.push({a_x,a_y});
    dis[a_x][a_y] = 0;
    while(!que.empty() && !vis[b_x][b_y]){
        auto it = que.front();
        que.pop();
        for(int i = 0;i < 4;i++){
            int px=it.x,py=it.y;
            px += dx[i],py += dy[i];
            while(!matix[px][py]){
                if(!vis[px][py]){
                    dis[px][py] = dis[it.x][it.y] + 1;
                    vis[px][py] = 1;
                    que.push({px,py});
                }
                px += dx[i],py += dy[i];
            }
        }
    }
    printf("%d\n",vis[b_x][b_y] ? dis[b_x][b_y] : -1);
    return 0;
}