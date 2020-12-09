#include<iostream>
#include<set>

using namespace std;
const int node = 5000;

int n,m,di[node],di_it[10000],pre_ti=1,ti,ans,temp;
set<int> attck;


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
        cin>>di[i];
    for(int i = 1;i <= m;i++){
        cin>>ti;
        for(int k =pre_ti;k <= ti;k++){
            attck.insert(di[k]);
            di_it[di[k]]++;
        }
        pre_ti = ti+1;
        cout<<
    }
    cout<<ans<<endl;
    return 0;
}