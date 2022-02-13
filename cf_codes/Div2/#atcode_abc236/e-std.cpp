//Jakon: 
#include <bits/stdc++.h>
#define dd double
#define int long long
#define PII pair<int,int>
#define ULL unsigned long long
using namespace std;
const dd eps = 1e-6;
const int mod = 1000000007;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 100010;

int n, a[N];
dd dp[N];

bool check_ave(dd x)
{
    dp[1] = 1.0 * a[1] - x;
    for(int i = 2; i <= n; i++)
    {
        dd tmp = 1.0 * a[i] - x;
        dp[i] = max(dp[i-1]+tmp, dp[i-2]+tmp);
    }
    return (dp[n]+eps > 0 || dp[n-1]+eps > 0);
}

bool check_mid(int x)
{
    int now = 0;
    bool flag = 1;
    for(int i = 1; i <= n; i++)
    {
        if(flag && a[i] < x) { flag = 0; continue;}
        else flag = 1, now += (a[i] >= x ? 1 : -1);
    }
    return now > 0;
}

void max_ave()
{
    dd l = 0, r = 1e9;
    while(r - l > eps)
    {
        dd mid = (l + r) / 2;
        if(check_ave(mid)) l = mid;
        else r = mid;
    }
    printf("%.9f\n", l);
}

void max_mid()
{
    int l = 1, r = 1e9;
    while(l <= r)
    {
        int mid = l + r >> 1;
        if(check_mid(mid)) l = mid + 1;
        else r = mid - 1;
    }
    printf("%lld\n", l-1);
}

signed main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
    cin >> n;
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    max_ave();
    max_mid();

	return 0;
}