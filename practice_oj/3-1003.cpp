#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int m,n;
vector<int> num;
int act[1001];

int func_1(int m,int n,int temp = 0,int win = 0){
    int max_num = m*n;
    for(int i = 1;i <= n;i++){
        cin>>temp;
        num.push_back(temp);
        act[temp] = 1;
    }
    sort(num.begin(),num.end());
    for(int i = n-1;i >= 0;i--){
        while(act[max_num])
            max_num--;
        if(num[i] < max_num)
            act[max_num] = 1;
        else
            win++;
    }
    num.clear();
    memset(act,0,sizeof act);
    return win;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    while(cin>>m>>n,n)
        cout<<"Case "<<t++<<": "<<func_1(m,n)<<endl;
}
