#include <cstdio>
#include <cstring>
typedef long long ll;
const long long mod = 1e9 + 7;
const long long modd = 1e9 + 6;
struct Matrix{
	int n, m;
	ll a[3][3];
	void clear()
	{
		n = m = 0;
		memset(a, 0, sizeof(a));
	}
	void init (int x)
	{
		n = m = 3;
		memset(a, 0, sizeof(a));
		if(x) 
			for(int i = 0; i < 3; i++)
				a[i][i] = 1;

    }
	Matrix operator *(const Matrix &b) const
	{
		Matrix tmp;
		tmp.clear();
		tmp.n = n;
		tmp.m = b.m;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < b.m; j++)
				for(int k = 0; k < m; k++)
					(tmp.a[i][j] += a[i][k] * b.a[k][j] % mod) %= mod;
		return tmp;
	}
	Matrix qpow(ll b)
	{
		Matrix ans, p = *this;
		ans.n = p.n;  
		ans.init(1);
		while (b)
		{
			if (b & 1) ans = ans * p;
			p = p * p;
			b >>= 1;
		}
		return ans;
	}
};
int main()
{
	ll t, n, b;
	Matrix tmp;
	tmp.clear();
	tmp.n = 3;
	tmp.m = 3;
	tmp.a[0][0] = 2, tmp.a[0][1] = 0, tmp.a[0][2] = 0;
	tmp.a[1][0] = 1, tmp.a[1][1] = 0, tmp.a[1][2] = 0;
	tmp.a[2][0] = 1, tmp.a[2][1] = 0, tmp.a[2][2] = 0;
	//freopen("wyh族谱随机.in","r", stdin);
	//freopen("wyh族谱随机.out","w", stdout);
	while(~scanf("%lld", &t)){
		while(t--){
			scanf("%lld", &n);
			if(n == 1 || n == 2 ){
				printf("%lld\n", n);
				continue;
			}
			Matrix p;
			p.clear();
			p.n = p.m = 3;
			p.a[0][0] = 1, p.a[0][1] = 1, p.a[0][2] = 1;
			p.a[1][0] = 1, p.a[1][1] = 0, p.a[1][2] = 0;
			p.a[2][0] = 0, p.a[2][1] = 0, p.a[2][2] = 1;
			//printf("%d\n", f(n, b, b, mod));
			Matrix ans = p.qpow(n - 2) * tmp;
			printf("%lld\n", ans.a[0][0]);
		}
	}
	return 0;
}
