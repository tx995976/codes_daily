#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<cstring>

const int max_n = 1e2+10;

int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};

char table[max_n][max_n][max_n];
int dis[max_n][max_n][max_n];
int n;

struct xyz{
    int x,y,z;
};

int bfs(){
    std::deque<xyz> pos;
    std::memset(dis,0,sizeof(dis));
    pos.push_back({1,1,1});
    dis[1][1][1] = 1;
    while(!pos.empty()){
        xyz n_pos = pos.front();
        pos.pop_front();
        for(int i = 0;i <= 5;i++){
            int x = n_pos.x + dx[i];
            int y = n_pos.y + dy[i];
            int z = n_pos.z + dz[i];
            if(x>=1 && x<=n && y>=1 && y<=n && z >=1 && z<=n && dis[x][y][z] == 0 && table[x][y][z] != '*'){
                dis[x][y][z] = dis[n_pos.x][n_pos.y][n_pos.z] + 1;
                pos.push_back({x,y,z});
            }
        }
    }
    if(dis[n][n][n])
        return dis[n][n][n];
    return -1;
    
}

int main(){
    scanf(" %d",&n);
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            for(int k = 1;k <= n;k++)
                scanf(" %c",&table[i][j][k]);
    printf("%d\n",bfs());
    return 0;
}
