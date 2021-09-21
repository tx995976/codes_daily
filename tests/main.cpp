#include<bits/stdc++.h>
using namespace std;
    int n,m,a,b,c=1;
    
    struct er{
        int des[100001];
        char human[100001][12];
    }people;
int main(){    
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>people.des[i]>>people.human[i];
    }
    for(int i = 1;i<=m;i++){
        cin>>a>>b;
        if(a^people.des[c]==0){c=(c-b+n)%n;}//顺时针
        if(a^people.des[c]==1){c=(c+b+n)%n;}//逆时针
        c=(c?c:n);           
    }
    cout<<people.human[c];

return 0;
}