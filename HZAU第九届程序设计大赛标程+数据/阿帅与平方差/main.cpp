/*#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e7+5;
int f[maxn];

void init()
{
   f[0]=0;
   f[1]=1;
   for(int i=2;i<maxn;i++)
   {
       if(i%2 == 1 || i%4 == 0)
         f[i]=f[i-1]+1;
       else
         f[i]=f[i-1];
   }
}

int main()
{
    init();
    int a,b;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",f[b]-f[a-1]);
    }
    return 0;
}
*/



#include <cstdio>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        int ans = b/2 + (b%2 > 0) - a/2 - (a%2 > 0);
        ans += b/4 - a/4;
        printf("%d\n", ans);
    }
    return 0;
}

