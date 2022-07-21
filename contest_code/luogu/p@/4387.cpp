#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>

using namespace std;

const int node = 1e5+50;
int t,n,temp,ans;
stack<int>num;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    for(t;t > 0;t--){
        int push_num[node],pop_num[node],k = 1;
        cin>>n;
        for(int i = 1;i <= n;i++)
            cin>>push_num[i];
        for(int i = 1;i <= n;i++)
            cin>>pop_num[i];
        for(int i = 1;i <= n;i++){
            num.push(push_num[i]);
            while(num.top() == pop_num[k]){
                num.pop(),k++;
                if(num.empty())
                    break;
            }
        }
        if(!num.empty())
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
        while(!num.empty())
            num.pop();
    }
    return 0;
}