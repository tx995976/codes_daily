#include<iostream>

using namespace std;

const int node = 100000;
int n,a_n[node],it_1;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    if(n == 1){
        cout<<"AniuZY"<<endl;
        return 0;
    }
    for(int i = 1;i <= n;i++){
        cin>>a_n[i];
        if(a_n[i]==1)
            it_1++;
    }
    if(it_1 == 0){
        cout<<"AniuZY"<<endl;
        return 0;
    }
    else if()
    
}