//#搜索/dfs
//
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

int pan[17][17];
int hx,hy,dx,dy,n,m,k,x1,y1,x2,y2;
int ans = INT32_MAX;
int cx[] = {1,-1,0,0};
int cy[] = {0,0,1,-1};

void dfs(int x,int y,int ab,int dis_w){
    if(x < 0 || y < 0 || x >= n || y >= m || pan[x][y] == -2)
        return;
    if(pan[x][y] == -1){
        ans = std::min(ans,ab);
        return;
    }
    else if(pan[x][y] == 0){
        pan[x][y] = -2;
        for(int i = 0;i < 4;i++)
            dfs(x+cx[i],y+cy[i],ab,dis_w);
        pan[x][y] = 0;
    }
    else{
        int w = pan[x][y];
        if((dis_w & (1<<(pan[x][y]-1))) == 0){
            dis_w ^= 1<<(pan[x][y]-1);
            ab += 1;
        }
        pan[x][y] = -2;
        for(int i = 0;i < 4;i++)
            dfs(x+cx[i],y+cy[i],ab,dis_w);
        pan[x][y] = w;
    }
    return;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ans = INT32_MAX;
        memset(pan,0,sizeof(pan));

        scanf("%d %d %d",&n,&m,&k);
        scanf("%d %d %d %d",&hx,&hy,&dx,&dy);
        pan[dx][dy] = -1;
        for(int i = 0;i < k;i++){
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            if(x1 == x2){
                int s = std::min(y1,y2);
                for(s;s <= std::max(y1,y2);s++)
                    pan[x1][s] = i;
            }
            else{
                int s = std::min(x1,x2);
                for(s;s <= std::max(x1,x2);s++)
                    pan[s][y1] = i;
            }
        }
        dfs(hx,hy,0,0);
        printf("%d\n",ans);
    }
    return 0;
}