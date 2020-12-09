#include<iostream>

using namespace std;

const int node = 500010;
int n,num[node],c[node],k;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>num[i];
        c[num[i]]++;
    }
    for(int i = 1;i <= n;i++){
        int temp = num[i],ans=0;
        if(temp == 1){
            cout<<c[1]-1<<endl;
            continue;
        }
        for(k =2;k*k < temp;k++){
            if(temp%k == 0)
                ans+=c[k],
                ans+=c[temp/k];
        }       
        if(k*k==temp)
            ans+=c[k];
        ans=ans+c[1]+c[temp]-1;
        cout<<ans<<endl;
    }
    return 0;
}