#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>


using namespace std;

const int node_1 = 100100;
int grade[node_1],ans[node_1];
int n,min_1,sum,item;
double everage = 0,temp;

void func_1(){
    min_1 = grade[n],sum = grade[n];
    for(int i = n-1;i >= 2;i--){
        min_1 = min(grade[i],min_1);
        sum += grade[i];
        temp = double(sum-min_1)/double(n-i);
        if(temp > everage){
            item = 1;
            ans[item] = i-1;
            everage = temp;
        }
        else if(everage == temp)
            ans[++item] = i-1;
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i = 1;i <= n;i++)
        cin>>grade[i];
    func_1();
    for(int i = item; i >= 1;i--)
        cout<<ans[i]<<endl;
    return 0;
}