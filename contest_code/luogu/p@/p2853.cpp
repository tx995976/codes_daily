#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int node = 10100;
vector<int> tree[node];
int cow[node],garden[1010];
int k,n,m,a,b,total;
bool reached[node];

void cow_dfs(int id){
    reached[id] = 1;
    garden[id] += 1;
    for(int i = 0;i  < tree[id].size();i++)
        if(!reached[tree[id][i]])
            cow_dfs(tree[id][i]);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>k>>n>>m;
    for(int i = 1;i <= k;i++)
        cin>>cow[i];
    for(int i = 1;i <= m;i++){
        cin>>a>>b;
        tree[a].push_back(b);
        }
    for(int i = 1;i <= k;i++){
        cow_dfs(cow[i]);
        memset(reached,0,sizeof(reached));      
    }
    for(int i = 1;i <= n;i++){
        if(garden[i] >= k)
            total++;
    }
    cout<<total<<endl;
    return 0;
}