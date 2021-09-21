#include<bits/stdc++.h>
using namespace std;
int main(){
    int m=0,n=0,l=1,w=1;
    cin>>n>>m;
    int data[105][105];
    char temp;
    //数据读入
    memset(data,0,sizeof(data));
    while(cin>>temp){
        if(temp=='?'){data[w][l++]=0;}
        if(temp=='*'){data[w][l++]=1;}
        if(l>m){l=1,w++;}
        if(w>n) break;
    }
    //处理
    
    for(int w=1;w<=n;w++){
        for(int l = 1;l<=m;l++){
            if(data[w][l]==1){cout<<"*";}
            else if(data[w][l]==0){
                printf("%d",data[w+1][l+1]+data[w+1][l]+data[w+1][l-1]+data[w][l+1]+data[w][l-1]+data[w-1][l+1]+data[w-1][l]+data[w-1][l-1]);
            }
        }
        cout<<"\n";       
    }
    
   return 0;
}