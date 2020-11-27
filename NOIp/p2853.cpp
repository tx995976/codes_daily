#include<iostream>
#include<vector>
#include<map>

using namespace std;

const int node = 10100;
map<int,int> tree_cow;
vector<int> tree[node];
int reached[node],cow[node];
int k,n,m,a,b,total;

void cow_dfs(int id){
    reached[id] += 1;
    for(int i = 0;i < tree[id].size();i++)
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

    return 0;
}