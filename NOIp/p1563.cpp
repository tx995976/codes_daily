#include<bits/stdc++.h>
using namespace std;
    int n,m,a,b,c=1;
    struct er{
        int des;
        string human;
    }people[100001];
int main(){    
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>people[i].des>>people[i].human;
    }
    for(int i = 1;i<=m;i++){
        cin>>a>>b;
        if(a^people[c].des==0){
            c-=b;
            if(c<1){c+=n;}
        }
        else{
            c+=b;
            if(c>n){c-=n;}
        }      
    }
    cout<<people[c].human;

return 0;

}