#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

const int const_node_string = 5e4+10;
int num_node = 1,father_node;
map<string,int> hash_tree;
struct tree{
    string num;
    int r_node;
}   tree_node[const_node_string];

void tree_add(int father_node,int node){
    tree_node[node].r_node = father_node;
}

void node_check(string node){
    if(hash_tree.find(node) == hash_tree.end()){
        int temp = num_node++;
        hash_tree[node] = temp;
        tree_node[temp].num = node;
    }
}

string node_search(string node){
    int temp = hash_tree.find(node)->second;
    while(tree_node[temp].r_node != 0)
        temp = tree_node[temp].r_node;
    return tree_node[temp].num;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string temp;
    cin>>temp;
    while(temp[0] != '$'){
        if(temp[0] =='#'){
            temp.erase(temp.begin());
            node_check(temp);
            father_node = hash_tree.find(temp)->second;
        }
        else if(temp[0] == '+'){
            temp.erase(temp.begin());
            node_check(temp);
            tree_add(father_node,hash_tree.find(temp)->second);
        }
        else{
            temp.erase(temp.begin());
            node_check(temp);
            cout<<temp<<" "<<node_search(temp)<<endl;
        }
        cin>>temp;
    }
    return 0;
}