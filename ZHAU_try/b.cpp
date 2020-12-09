#include<iostream>
#include<map>

using namespace std;
const int node = 5000;

int n,m,di[node],pre_ti=1,ti,ans;
map<int,int> attck;
map<int,int>::iterator now,now1;

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
        now1 = --now;
        ans+=((now1)->first);
        if(--(now1->second) == 0);
            attck.erase(now1);            //c++11前的标准，这句导致RE；
    }
    cout<<ans<<endl;
    return 0;
}