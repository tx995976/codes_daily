#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>

#pragma gcc optimize(2)

using namespace std;


int n,ans;
priority_queue<int,vector<int>,greater<int>> num;

int func_1(){
    int a,b,c;//1 2 3
    int temp = num.size();
    while(num.size() >= 2){
        a = num.top();num.pop();
        b = num.top();num.pop();
        c = a+b,ans += c;
        num.push(c);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int temp;
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>temp;
        num.push(temp);
    }
    cout<<func_1()<<endl;
    return 0;
}