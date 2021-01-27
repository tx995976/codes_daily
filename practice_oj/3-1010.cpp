#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

class num{
    public:
    int w;
    int s;
};

num node[100010];
num temp;
int n,min_1 = 0;

bool compare (num a,num b){
    return (a.w+a.s) < (b.w+b.s);
}

int func_1(){
    int i = 0,all_w = 0,pdv_temp;
    sort(node,node+n,compare);
    for(i;i < n;i++){
        min_1 = max(min_1,(all_w - node[i].s) < 0 ? 0 : all_w - node[i].s);
        all_w += node[i].w;
    }
    return min_1;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    while(cin>>n){
        for(int i = 0;i < n;i++){
            cin>>node[i].w>>node[i].s;
        }
        cout<<func_1()<<endl;
        min_1 = 0;
    }
    return 0;
}