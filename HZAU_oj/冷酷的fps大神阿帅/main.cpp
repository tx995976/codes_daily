#include<bits/stdc++.h>
using namespace std;
const long long maxn = 15;
long long a[maxn];
long long len[maxn];
long long f[maxn];
long long n,m;


long long pow_m(long long a, long long b) {
    long long ans = 1;
    for (; b; a = (a * a), b >>= 1)
        if (b & 1)
            ans = (ans * a);
    return ans;
}

int main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%lld",&a[i]);
    if(m==0)
    {
        printf("0\n");
        return 0;
    }
    sort(a+1,a+m+1);
    len[1]=a[1]-1;
    len[m+1]=n-a[m];
    for(int i=2;i<=m;i++)
    {
        len[i]=a[i]-a[i-1]-1;
    }
    f[0]=1;
    f[1]=1;
    for(int i=2;i<=maxn-1;i++)
    {
        f[i]=f[i-1]*i;
    }
    long long ans=f[n-m];
    for(int i=1;i<=m+1;i++)
    {
        if(len[i]==0) continue;
        ans/=f[len[i]];
    }
    for(int i=2;i<=m;i++)
    {
        if(len[i]==0) continue;
        ans=ans*pow_m(2,len[i]-1);
    }
    printf("%lld\n",ans);
    return 0;
}
