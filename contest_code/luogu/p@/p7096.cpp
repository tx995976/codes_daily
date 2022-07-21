#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int i;
    cin>>i;
    if(i&1){cout<<-1;return 0;}
    for(int k=31;k>=0;k--){
        if((i>>k)&1)
            cout<<(1<<k)<<" ";
        }
    return 0;
    }
