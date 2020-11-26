#include<bits/stdc++.h>
using namespace std;

int n,m,tree1[310],tree2[620],tree3[310],id_tree,c[620],cnt[310];
vector<int> tree_level[310];
int result = 310;

void cin_in(int i, int j){
    tree2[id_tree] = j;
    tree3[id_tree] = tree1[i];
    tree1[i] = id_tree++;
}

int dfs_lv(int a,int b,int c){
    cnt[a] = 1;
    for(int i = tree1[a];i>=0;i=tree3[i]){
        int j =tree2[i];
        if(j == c)
            continue;
        cnt[a] += dfs_lv(j,b+1,a);
        tree_level[b].push_back(i);
    }
    return cnt[a];
}

void dfs_draw(int j, int kind){
    c[j] = kind;
    for(int i = tree1[tree2[j]];i>=0;i = tree3[i])
        if(i !=(j ^ 1))
            dfs_draw(i,kind);
}

void dfs(int a,int s){
    result = min(result,s);
    for( int i = 0; i<tree_level[a].size();i++){
        int j = tree_level[a][i];
        if(!c[j]){
            dfs_draw(j, 1);
            dfs(a+1, s - cnt[tree2[j]]);
            dfs_draw(j,0);
        }
    }    
}


int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    memset(tree1, -1, sizeof tree1);
    for(int k = 1;k<=m;k++){
        int p_1,p_2;
        cin>>p_1>>p_2;
        cin_in(p_1,p_2);cin_in(p_2,p_1);
    }    
    dfs_lv(1, 0, -1);
    dfs(0,n);
    cout<<result<<endl;
    return 0;
}


















