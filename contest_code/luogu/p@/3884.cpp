#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

const int node_int = 110;
int deep_num[node_int],deep_max;
string t;


class tree{
    public:
    int deep;
    int r_node;
}   tree_node[node_int];

int tree_find(int a,int b){
    while(tree_node[a].deep > tree_node[b].deep){
        a = tree_node[a].r_node;
    }
    while(tree_node[a].deep < tree_node[b].deep){
        b = tree_node[b].r_node;
    }
    while(a != b){
        b = tree_node[b].r_node;
        a = tree_node[a].r_node;
    }
    return a;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int k,a,b;
    cin>>k;
    tree_node[1].deep = 1;
    for(int i = 1;i < k;i++){
        cin>>a>>b;
        tree_node[b].r_node = a;
        tree_node[b].deep = tree_node[a].deep+1;
        deep_num[tree_node[b].deep]++;
        deep_max = max(deep_max,tree_node[b].deep);
    }
    cin>>a>>b;
    auto num_max = max_element(deep_num+1,deep_num+deep_max+1);
    int node_middle = tree_find(a,b);
    cout<<deep_max<<endl<<*num_max<<endl;
    cout<<(tree_node[a].deep-tree_node[node_middle].deep)*2 + (tree_node[b].deep - tree_node[node_middle].deep)<<endl;   
    return 0;
}