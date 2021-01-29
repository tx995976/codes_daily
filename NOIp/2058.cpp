#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

class node{
    public:
    int t;
    int x;
};

const int num = 1e5+10;
int n,t,k,ans;
int num_city[num];
queue<node> queue_num;
node temp;

int func_1(){
    cin>>t>>k;
    //处理超时
    while(!queue_num.empty()){
        temp = queue_num.front();
        if(temp.t <= t-86400){
            queue_num.pop();
            num_city[temp.x]--;
            if(num_city[temp.x]==0)
                ans--;
            continue;
        }
        break;
    }
    //录入
    temp.t = t;
    for(k;k > 0;k--){
        cin>>temp.x;
        queue_num.push(temp);
        num_city[temp.x]++;
        if(num_city[temp.x] == 1)
            ans++;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(n;n > 0;n--)
        cout<<func_1()<<endl;
    return 0;
}