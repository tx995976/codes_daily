#include<bits/stdc++.h>
using namespace std;
int number[100000];
int n,m,times;
int mid,all,lef,rig;
inline bool count_m(int mid){
    for(int i = 0;i<n;i++){
        if(all+number[i]<=mid){all+=number[i];}
        else{
            all=number[i];
            times++;
        }
    }
    return times>=m;
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        cin>>number[i];
        rig+=number[i];
        lef=lef>number[i]?lef:number[i];
    }
    //二分处理
    while(lef<=rig){
        mid=(lef+rig)/2;
        all=0,times=0;
        if(count_m(mid))lef=mid+1;
        else            rig=mid-1;
    }
    cout<<lef;
    return 0;
}