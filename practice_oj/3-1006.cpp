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
    while(~scanf("%d", &n)){
        for(n;n > 0;n--){
            scanf("%d", &temp);
            node[temp]++;
            ans = max(ans,node[temp]);
        }
        cout<<ans<<endl;
        node.clear();
        ans = 0;
    } 
    return 0;
}