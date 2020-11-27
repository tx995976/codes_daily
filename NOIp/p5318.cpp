#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

const int node = 1000010;
int n,m,a,b;

queue<int> q_bfs;
bool searched[node];
vector<int> tree[node];

void dfs(int num,int item){
    searched[num] = 1;
    cout<<num<<" ";
    if(item == n) return;
    for(int k = 0;k < tree[num].size();k++)
        if(!searched[tree[num][k]])
            dfs(tree[num][k],item+1);
}

inline void bfs(int num){
    memset(searched,0,sizeof(searched));
    searched[num] = 1;
    q_bfs.push(num);
    while(!q_bfs.empty()){
        int a = q_bfs.front();  q_bfs.pop();
        cout<<a<<" ";
        for(int k = 0;k < tree[a].size();k++)
            if(!searched[tree[a][k]]){
                q_bfs.push(tree[a][k]);
                searched[tree[a][k]] = 1;
            }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i = 1;i <= m; i++){
        cin>>a>>b;
        tree[a].push_back(b);
    }
    for(int i = 1;i <= n;i++)
        sort(tree[i].begin(),tree[i].end());
    dfs(1,0);   
    cout<<endl;
    bfs(1);
    cout<<endl;
    return 0;       
}