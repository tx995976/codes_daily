#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<set>
#include<vector>

using ll = long long;
const int max_n = 2e5+10;

int X,Y,N;
ll ans=0ll;
int _XY[max_n],_X[max_n],_Y[max_n],R[max_n],A[max_n];

ll get_seq(int a[]){
    ll res=0,len=0;
    for(int i = 1;i <= N;i++){
        if(a[i] == 1){
            res += len * (len + 1)/2;
            len = 0ll;
        }
        else
            len += 1ll;
    }
    res += len * (len + 1)/2;
    return res;
}

int main(){
    scanf(" %d %d %d",&N,&X,&Y);
    for(int i = 1;i <= N;i++)
        scanf(" %d",&A[i]);
    for(int i = 1;i <= N;i++){
        if(!(Y <= A[i] && A[i] <= X)){
           _XY[i]=_X[i]=_Y[i]=R[i]=1; 
        }
        if(A[i] == X)
            _X[i]=_XY[i]=1;
        if(A[i] == Y)
            _Y[i]=_XY[i]=1;
    }
    ans = get_seq(R)-get_seq(_X)-get_seq(_Y)+get_seq(_XY);
    printf("%lld\n",ans);
    return 0;
}