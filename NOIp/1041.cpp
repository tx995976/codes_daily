#include<bits/stdc++.h>
using namespace std;

int tree[310][310],vis[310];

inline void add(int a,int b){
    tree[a][b]=tree[b][a]=1;
}

void test(int a,int b){
    
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int a,b,n,p,all;
    queue<int> ready;
    cin>>n>>p;
    all=1;
    for(int i = 1;i<=p;i++){
        cin>>a>>b;
        add(a,b);
    }
    vis[1]=1;
        for(int j = 1;j<=n;j++){
            if(!vis[j]){
                if(tree[1][j]==1){
                    vis[j]=1;
                    all++;
                }
            }
        }
    
    cout<<all<<endl;
    return 0;
}

















