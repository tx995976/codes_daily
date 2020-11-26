#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int main(){
    queue<int> q;
    int  n,m,k;
    cin>>n>>m>>k;
    q.push(n);
    q.push(m);
    q.push(k);
    cout<<q.front();
    q.pop();
    cout<<q.front();
    
}