#include <bits/stdc++.h>
using namespace std;
long long num[5000020];
inline int fast_read(){
    char in=getchar();
    int a=0,cha=1;
    while(in<'0'||in>'9'){
        if(in=='-')cha=-1;
        in=getchar();
    }
    while(in>='0'&&in<='9'){
        a=a*10+in-'0';
        in=getchar();
    }
    return a*cha;
}
 
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        num[i]=fast_read();
    }
    sort(num,num+n);
    cout<<num[k];
    return 0;
}