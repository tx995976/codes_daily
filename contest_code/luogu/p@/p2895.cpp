#include<bits/stdc++.h>
using namespace std;
int n,hit[350][350],foot[350][350],tx,ty,tim,result[350][350];
int sign_x[5]={0,0,0,1,-1},           //依次代表 中 上 下 左 右
    sign_y[5]={0,1,-1,0,0};

int jug(int a){
    if(a==-1)
        return 99999;
    else
        return a;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i = 0;i<305;i++){
        for(int k = 0;k<305;k++){
            hit[i][k]=-1;
        }      
    }                                   //完成初始化

    for(int k = 1;k<=n;k++){
        cin>>tx>>ty>>tim;
        for(int i = 0;i<5;i++){
            if(tx+sign_x[i]>=0&&ty+sign_y[i]>=0&&(hit[tx+sign_x[i]][ty+sign_y[i]]==-1||hit[tx+sign_x[i]][ty+sign_y[i]]>tim))
                hit[tx+sign_x[i]][ty+sign_y[i]]=tim;
        }                   //完成石头标记
    }
    queue<int> a[2];
    foot[0][0] = 1;
    a[0].push(0);a[1].push(0);
    while(!a[0].empty()){
        int x=a[0].front(),y=a[1].front();
        a[0].pop();a[1].pop();
        int re = result[x][y]+1;
        if(hit[x][y]==-1){
            cout<<re-1<<endl;
            return 0;
        }
        for(int k = 1;k<=4;k++){
            int xx=x+sign_x[k],yy=y+sign_y[k];
            if(xx>=0&&yy>=0&&re<jug(hit[xx][yy])&&foot[xx][yy]==0){
                a[0].push(xx);a[1].push(yy);
                foot[xx][yy]=1;
                result[xx][yy]=re;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}