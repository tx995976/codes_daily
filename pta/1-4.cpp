#include<iostream> 

using namespace std;

int search(int i){
    int ans=0,k;
    for(k = 2;k*k < i;k++)
        if(i%k == 0)
            ans+=k+(i/k);
    if(k*k == i)
        ans+=k;
    return ans+1;
}

int main(){ 
    ios::sync_with_stdio(0);
    for(int i = 2;i <= 1000;i++)
        if(i == search(i))
            cout<<i<<endl;
    return 0;
}