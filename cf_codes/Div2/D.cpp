#include <cstdio>
#include <iostream>
#include <vector>

const int max_node = 2e5+1;

std::vector<int> tree[max_node];
bool find[max_node];

void find_node(int head_node,int this_node,int round,int line = 0){
    find[this_node] = 1;
    

}

void tree_build(){
    int j =0,u,v;
    std::scanf("%d",&j);
    if(j == 1){
        std::cout<<"1\n";
        return;
    }
    for(int i = 1;i<j;i++){
        std::scanf("%d %d",&u,&v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    } 
    for(int i = 1;i<=j;i++){
        find_node(i,i,0);
    }
    while(j > 0){
        tree[j].clear();
        j--;
    }
}

int main(){
    int i;
    std::scanf("%d",&i);
    while(i-- > 0)
        tree_build();
    return 0;
}
