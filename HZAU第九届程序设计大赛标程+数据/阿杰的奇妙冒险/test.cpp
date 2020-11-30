#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int mp[maxn][maxn];
int a[maxn];
int main()
{
	int n, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d",&n);
        //fscanf(re, "%d",&n);
        //scanf("%d",&n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                scanf("%d",&mp[i][j]);
                //scanf("%d",&mp[i][j]);
            }
        int p=1,cnt=0,res;
        for(int i=2;i<n;i++)
        {
            res=a[++cnt]=sqrt((mp[i][p]*mp[i+1][p])/mp[i+1][p+1]);
            p++;
        }
        int tmp=a[++cnt]=mp[n-1][n-2]/res;
        a[++cnt]=mp[n][n-1]/tmp;
        //fprintf(out, "%d\n", n);
        for(int i=1;i<=cnt;i++)
            printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}

