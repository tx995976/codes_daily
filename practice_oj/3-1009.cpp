#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

class node{
    public: 
    int p;
    int m;
};
vector<node> num;
node temp;
int n,v,ans = 0;

bool compare(node a,node b){
    return a.p > b.p;
}

int func_1(){
    int i = 0;
    sort(num.begin(),num.end(),compare);
    while(v != 0&&i < n){
        if(num[i].m <= v){
            ans += num[i].m*num[i].p;
            v -= num[i].m;
        }
        else{
            ans += v*num[i].p;
            v = 0;
        }
        i++;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    while(1){
        cin>>v;
        if(v == 0)
            break;
        cin>>n;
        for(int i = 1;i <= n;i++){
            cin>>temp.p>>temp.m;
            num.push_back(temp);
        }
        cout<<func_1()<<endl;
        num.clear();
        ans = 0;
    }
    return 0;
}