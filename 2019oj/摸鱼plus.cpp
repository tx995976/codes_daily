#include <cstdio>
#include <cmath>
typedef long long LL;
int log2(LL m)
{
	return (int)(log(m) / log(2));
}
bool call(LL n, LL m)
{
	int x = log2(m);
	LL t = 1ll << x;
	//printf("%d\n", x);
	int p = 0;
	LL tp = t;
	while(m > (t + 1)){
		tp >>= 1;
		t += tp;
		p++;
	}
	//printf("%d\n", p);
	LL mod = (1ll << (x + 1)) - 2 + (!p ? m : (m << 1) + (1ll << (x - p + 1)) - 2);
	LL tmp = n % mod, tmp1 = 1 + m;
	//printf("%lld\n", mod);
	if(tmp == 1){
		return true;
	}
	for(int i = 0; i < x; i++){
		//printf("%lld\n", tmp1);
		if(tmp == tmp1){
			return true;
		}
		tmp1 += (1ll << (i + 1));
	}
	//printf("h%lld %lld\n", tmp, tmp1);
	if(tmp1 == tmp || tmp1 + m == tmp){
		return true;
	}
	return false;
}

int main()
{
	int t;
	LL n, m;
	//freopen("ÃþÓãplusËæ»ú.in","r", stdin);
	//freopen("ÃþÓãplusËæ»ú.out","w", stdout);
	while(~scanf("%d", &t)){
		while(t--){
			scanf("%lld %lld", &n, &m);
			printf("%s\n", call(n, m + 2) ? "hyy" : "wqy");
		}
	}
	return 0;
}
