#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;
using itor_vec = vector<int>::const_iterator;

struct compare{
    bool operator()(const int& a,const int& b)  const{
        return a<b;
    }
};

const int node = 1000010;

queue<int> q_bfs;
set<int> tree[node];
bool searched[node];


int dfs(){

}

int bfs(){

}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m,a,b;
    cin>>n>>m;
    for(int i = 1;i <= m; i++){
        cin>>a>>b;
        tree[a].insert(b);
    }
    


}