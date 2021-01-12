#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

int m,n;
set<int> count_num;

int func_1(int m,int n,int temp = 0,int win = 0,int ans = 0){
    int max_num = m*n;
    for(int i = 1;i <= n;i++){
        cin>>temp;
        count_num.insert(temp);
    }
    for(int i = m*n;i >= m*n-n+1;){
        while(!count_num.count(i) && i >= m*n-n+1)
            win--,i--;
        while(count_num.count(i) && i >= m*n-n+1)
            win++,i--;
        if(win > 0)
            ans += win,win = 0;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    while(cin>>m>>n){
        if(m == 0)
            break;
        cout<<"Case "<<t<<": "<<func_1(m,n)<<endl;
        t++;
    }

}
