#include<bits/stdc++.h>
using namespace std;
long long hill[301]{0},total;
int n;
int main(){
    cin>>n;
    int left=0,right=n;
    for(int i = 1;i<=n;i++){
        cin>>hill[i];
    }  
    sort(hill+1,hill+n+1);
    while(left<right){
        total+=pow((hill[right]-hill[left]),2);
        left++;
        total+=pow((hill[right]-hill[left]),2);
        right--;
    }
    cout<<total;
    return 0;
}