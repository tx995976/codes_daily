#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<set>

using namespace std;

int t,n,m,q,a,b,ans,tim;
vector<int> line[110];
set<int> wait;
queue<int> people;

inline void clr(){
    queue<int> emp;
    swap(emp,people);
}

void bfs(){
    int temp;
    ans = 0;
    people.push(1);
    while(!wait.empty()){
        int dig = 0;     tim++;
        if(people.empty()){
            cout<<"-1"<<endl;
            return;
        }
        temp = people.front();
        people.pop();
        for(int i = 0;i < line[temp].size();i++){
            people.push(line[temp][i]);
            
        }
        if(dig == 1)
            ans+=tim;
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    for(int i = 1;i <= t;i++){
        line->clear();  wait.clear();  clr();
        cin>>n>>m>>q;
        for(int k = 1;k <= q;k++){
            cin>>a;
            wait.insert(a);
        }
        for(int j = 1;j <= m;j++){
            cin>>a>>b;
            line[a].push_back(b);
        }
        bfs();
    }
    return 0;
}