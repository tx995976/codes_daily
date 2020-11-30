#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e6 + 2;

int t, n;
long long f[N][2];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out2.txt", "w", stdout);
    f[1][0] = 0;    f[1][1] = 1;
    for (int i = 2; i <= 1000000; ++i) {
        f[i][0] = f[i - 1][1] % MOD;
        f[i][1] = (f[i - 1][1] + f[i - 1][0]) % MOD;
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%lld\n", (f[n][0] + f[n][0] + f[n][1]) % MOD);
    }
    fclose(stdin);  fclose(stdout);
    return 0;
}
