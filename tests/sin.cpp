#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,ma,mi,i;
    cin>>a>>b>>c;
    ma=max(a,b),ma=max(ma,c),mi=min(a,b),mi=min(mi,c);
    for (int i = mi; i > 0; i--)
    {
        if ((ma%i == 0)&&(mi%i == 0))
        {
            ma=ma/i,mi=mi/i;
            break;
        }        
    }
    cout<<mi<<"/"<<ma;
    return 0;
}