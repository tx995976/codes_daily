#include <cstdio>
#include <iostream>
#include <vector>

const int max_node = 2e5+1;

std::vector<int> tree[max_node];
std::vector<int>part[2];
int bms[max_node];

/*
void find_node(int head_node,int this_node,int round,int line = 0){
    find[this_node] = 1;
    auto itor = tree[this_node].begin();
    for(;itor != tree[this_node].end();itor++){
        if(find[*itor] == 0 && ((*itor^this_node) <= (*itor < this_node ? *itor : this_node))){
            find_node(head_node,*itor,round+1);
            line++;
        }
    }
    find[this_node] = 0;
    if(line == 0 && (round & 1) == 0)
        ans[head_node] = 1;
    return;
}
*/

void bms_get(){
     int pos = 1,cnt=1,next=2;
     for(int i =1;i < max_node;i++){
        bms[i] = pos;
        if(--cnt == 0){
            cnt = next;
            next<<1;
        }
     }
}

void dfs_part(int this_node,int pre_node,int i){
    part[i].push_back(this_node);
        for(auto it :tree[this_node]){
            if(it == pre_node)
                continue;
            dfs_part(it,this_node,i^1);
        }
}

inline void tree_build(){
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
//////////////////////////////
    bms_get();
    dfs_part(1,1,0);


  /*  for(int i = 1;i<=j;i++){
        ans[i] = 0;
        find_node(i,i,1);
        if(ans[i] == 0){
            std::printf("%d ",i);
        }
    }
    std::printf("\n");
    while(j > 0){
        tree[j].clear();
        j--;
    }
    */
}
int main(){
    int i;
    std::scanf("%d",&i);
    while(i-- > 0)
        tree_build();
    return 0;
}
