#include<iostream>

using namespace std;

int a,b;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>a;
    if(a >= 2 && (a & 1) == 0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;    
    return 0;
}