#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

const int node = 50010;
int data_[node],first[node];
int n,k,now=2,max_first,max_rignt,ans;

int func_1(){
    sort(data_+1,data_+n+1);
    for(int i = 1;i <= n;i++){
        while(data_[i]+k >= data_[now])
            now++;
        first[now] = max(now-i,first[now]);
        max_first = max(max_first,first[i]);
        ans = max(ans,max_first+now-i);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(int i = 1;i <= n;i++)
        cin>>data_[i];
    data_[n+1] = INT32_MAX;
    cout<<func_1()<<endl;
    return 0;
}