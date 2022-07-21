#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct node{
    int num;
    int l_node;
    int r_node;
}tree[110];

int tree_node[110];
long long ans,dist[110];

void func_tree_dfs(int node_1,int node_pre,int deep){
    tree_node[node_1] = tree[node_1].num;
    dist[1] += tree_node[node_1] * deep;
    if(tree[node_1].l_node)
        func_tree_dfs(tree[node_1].l_node,node_1,deep+1);
    if(tree[node_1].r_node)
        func_tree_dfs(tree[node_1].r_node,node_1,deep+1);
    tree_node[node_pre] += tree_node[node_1];
}
void func_tree_dp(int node_1,int node_pre){
    if(tree[node_1].l_node){
        dist[tree[node_1].l_node] = dist[node_1]+tree_node[1]-tree_node[tree[node_1].l_node]* 2;
        ans = min(dist[tree[node_1].l_node],ans);
        func_tree_dp(tree[node_1].l_node,node_1);
    }
    if(tree[node_1].r_node != 0){
        dist[tree[node_1].r_node] = dist[node_1]+tree_node[1]-tree_node[tree[node_1].r_node]* 2;
        ans = min(dist[tree[node_1].r_node],ans);
        func_tree_dp(tree[node_1].r_node,node_1);
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int i;
    cin>>i;
    for(int k = 1; k <= i;k++)
        cin>>tree[k].num>>tree[k].l_node>>tree[k].r_node;
    func_tree_dfs(1,0,0);
    ans = dist[1];
    func_tree_dp(1,0);
    cout<<ans<<endl;
    return 0;
} 