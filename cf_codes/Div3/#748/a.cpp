#include<iostream>
#include<algorithm>

int i;
long a,b,c;

int main(){
    using namespace std;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>i;
    for(int y = 1; y <= i;y++){
        cin>>a>>b>>c;
        if(b-a >= 0 || c-a >= 0)
            cout<<max(b-a,c-a)+1<<" ";        
        else
            cout<<0<<" "; 
        if(a-b >= 0 || c-b >= 0)
            cout<<max(a-b,c-b)+1<<" ";        
        else
            cout<<0<<" "; 
        if(b-c >= 0 || a-c >= 0)
            cout<<max(b-c,a-c)+1<<endl;        
        else
            cout<<0<<endl; 
    }
    return 0;
}