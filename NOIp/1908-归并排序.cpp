#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

const int node = 5e5+10;
int num[node],temp[node],n;
long long ans = 0;

void func_1(int l,int r){
    if(r == l)
        return;
    int mid = (r + l)>>1;
    func_1(l,mid);
    func_1(mid+1,r);
    int a = l, b = mid+1,k = l;
    while(a <= mid && b <= r)
        if(num[a] <= num[b])
            temp[k++] = num[a++];
        else 
            temp[k++] = num[b++],ans += mid-a+1;
        while(a <= mid)
            temp[k++] = num[a++];
        while(b <= r)
            temp[k++] = num[b++];
        for(int i = l;i <= r;i++)
           num[i] = temp[i];
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i = 1;i <= n ;i++)
        cin>>num[i];
    func_1(1,n);
    cout<<ans<<endl;
    return 0;
}