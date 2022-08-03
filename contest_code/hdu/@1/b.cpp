//#搜索/dfs
//
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

int pan[20][20],hw[20][20],lw[20][20];
int hx,hy,dx,dy,n,m,k,x1,y1,x2,y2;
int ans;
struct p {int x1,y1,x2,y2;} wp[20];

int bitcnt(int x){
    int cnt = 0;
    while(x){
        if(x & 1) 
            cnt++;
        x >>= 1;
    }
    return cnt;
}

bool dfs(int x,int y){
    pan[x][y] = 1;
    if(x == dx && y == dy){
        return 1;
    }
    bool flag = 0;
    if(x > 0 && hw[x][y] == 0 && pan[x-1][y] == 0)
        flag |= dfs(x-1,y);
    if(x < n-1 && hw[x+1][y] == 0 && pan[x+1][y] == 0)
        flag |= dfs(x+1,y);
    if(y > 0 && lw[x][y] == 0 && pan[x][y-1] == 0)
        flag |= dfs(x,y-1);
    if(y < m-1 && lw[x][y+1] == 0 && pan[x][y+1] == 0)
        flag |= dfs(x,y+1);
    return flag;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ans = INT32_MAX;
        scanf("%d %d %d",&n,&m,&k);
        scanf("%d %d %d %d",&hx,&hy,&dx,&dy);

        for(int i = 0;i < k;i++)
            scanf("%d %d %d %d",&wp[i].x1,&wp[i].y1,&wp[i].x2,&wp[i].y2);

        for(int i = 0;i <(1<<k);i++){
            memset(pan,0,sizeof(pan));
            memset(hw,0,sizeof(hw));
            memset(lw,0,sizeof(lw));
            for(int j = 0;j < k;j++){
                if((i & (1 << j)) == 0)
                    if(wp[j].x1 == wp[j].x2){
                        int s = std::min(wp[j].y1,wp[j].y2);
                        for(s;s < std::max(wp[j].y1,wp[j].y2);s++)
                            hw[wp[j].x1][s] = 1;
                    }
                    else{
                        int s = std::min(wp[j].x1,wp[j].x2);
                        for(s;s < std::max(wp[j].x1,wp[j].x2);s++)
                            lw[s][wp[j].y1] = 1;
                    }
            }

            if(dfs(hx,hy)){
                ans = std::min(ans,bitcnt(i));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}