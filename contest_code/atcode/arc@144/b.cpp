//#算法基础/二分
//@
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

using ll = long long;
int n,a,b;
ll l = 0,r = INT32_MAX;
std::vector<ll> A;

int main(){
    scanf("%d %d %d",&n,&a,&b);
    A.resize(n);
    for(int i=0;i<n;i++){
       scanf("%lld",&A[i]);
    }
    while(l < r-1){
        ll mid = (r+l)/2;
        ll ai=0,bi=0;
        for(int it : A){
            if(it >= mid)
                bi += ((ll)it-mid)/b;
            else
                ai += (mid-it+(a-1))/a;
        }
        if(ai <= bi)
            l = mid;
        else
            r = mid;
    }
    printf("%lld\n",l);
    return 0;
}