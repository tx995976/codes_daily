#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<cstdio>

using namespace std;

map<int,int> node;
int temp;
int n,ans = 0;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    while(cin>>n){
        for(n;n > 0;n--){
            cin>>temp;
            node[temp]++;
            ans = max(ans,node[temp]);
        }
        cout<<ans<<endl;
        node.clear();
        ans = 0;
    } 
    return 0;
}