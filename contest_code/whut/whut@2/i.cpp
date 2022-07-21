#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>

const int max_n =1e5+10;
std::vector<int> tree[max_n];
int node_m = 1,node[max_n],n,m,a_i[max_n],b_i[max_n];
int result = 0,ans[max_n];

void dfs(int this_node,int power,int plus){
    power += a_i[this_node];
    if(tree[this_node].empty()){
        if(power < b_i[this_node])
            plus += b_i[this_node] - power;
        ans[this_node] = ans[this_node] < plus ? ans[this_node] : plus;
        return;
    }
    else{
        if(power < b_i[this_node]){
            plus += b_i[this_node] - power;
            power = b_i[this_node];
        }
        for(auto it : tree[this_node]){
            dfs(it,power,plus);
        }
    }
}

int main(){
    std::memset(ans,999999,sizeof(int)*max_n);
    int t_a,t_b;
    scanf("%d %d",&n,&m);
    for(int i=1 ;i <= n;i++){
        scanf("%d %d",&a_i[i],&b_i[i]);
    }
    for(int i = 1;i <= n-m;i++){
        scanf("%d %d",&t_a,&t_b);
        tree[t_a].push_back(t_b);
    }

    for(int i = 1;i <= n;i++){
        dfs(i,0,0);
        if(tree[i].empty())
            node[node_m++] = i;
    }

    for(int i = 1;i <= m;i++){
        result += ans[node[i]];
    }
    printf("%d\n",result);
    return 0;
}