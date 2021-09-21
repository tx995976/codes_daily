#include<iostream>
#include<cstring>

const int N=100050;
using namespace std;
int n,m,turn[N],pos;
string name[N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>turn[i]>>name[i];
    pos=1;
    for(int i=1;i<=m;i++)
    {
        int opt,x; cin>>opt>>x;
        if(opt^turn[pos]==1) pos=(pos+x+n)%n;
        else pos=(pos-x+n)%n;
        pos=(pos?pos:n);
    }
    cout<<name[pos];
    
    return 0;
}