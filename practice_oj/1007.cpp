#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int node = 100010;
int b,len=1,n;
int sys[node];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    while(cin>>n){
        len = 1;
        memset(sys,0,sizeof sys);
        cin>>sys[len];
        for(int i = 2;i <= n;i++){
            cin>>b;
            if(sys[len] < b){
                sys[++len] = b;
            }
            else{
                int *p = lower_bound(sys+1,sys+1+len,b);
                *p = b;
            }
        }
        cout<<len<<endl;
    }
    return 0;
}