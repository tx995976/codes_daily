#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int func_1(int n,int u,int d,int ans = 0,int high = 0){
    while(1){
        high += u;
        ans++;
        if(high >= n)
            break ;
        ans++;
        high -= d;
    }
    return ans;
}
cpp
int main(){
   ios::sync_with_stdio(0);cin.tie(0);
    int n,u,d;
    while(cin>>n>>u>>d){
        if(n == 0)
            break;
        cout<<func_1(n,u,d)<<endl;
    }
    return 0;
}