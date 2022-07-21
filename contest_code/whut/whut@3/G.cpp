#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

int chess[12][12];

int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {1,1,0,-1,-1,-1,0,1};

int main(){
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            scanf("%d",&chess[i][j]);
        }
    }
    for(int x = 0;x < 12;x++)
        for(int y = 0;y < 12;y++){
            if(chess[x][y] != 0)
                continue;
            for(int type = 1; type <= 2;type++)
                for(int l = -4;l <= 0;l++)
                    for(int dir = 0;dir < 8;dir++){
                        bool flag = 1;
                        for(int p = l;p <= l+4;p++){
                            if(p == 0)
                                continue;
                            int nx = x + p*dx[dir];
                            int ny = y + p*dy[dir];
                            if(nx < 0 || nx >= 12 || ny < 0 || ny >= 12){
                                flag = 0;
                                break;
                            }
                            if(chess[nx][ny] != type){
                                flag = 0;
                                break;
                            }
                        }
                        if(flag){
                            printf("YES\n");
                            return 0;
                        }
                    }
        }
    printf("NO\n");
    return 0;
}