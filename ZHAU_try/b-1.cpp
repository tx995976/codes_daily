#include<iostream>
#include<map>

using namespace std;
const int node = 5000;

int n,m,di[node],pre_ti=1,ti,ans,temp;
map<int,int> attck;
map<int,int>::iterator now;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
        cin>>di[i];
    for(int i = 1;i <= m;i++){
        cin>>ti;
        for(int k =pre_ti;k <= ti;k++)
            attck[di[k]]++;
        pre_ti = ti+1;
        now = attck.end();
        ans+=((--now)->first);
        temp = now->first;
        attck[temp]--;
        if(attck[temp] == 0)
            attck.erase(now);
    }
    cout<<ans<<endl;
    return 0;
}