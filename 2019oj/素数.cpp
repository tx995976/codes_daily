/*
��n�����֣�������ѡm������m����������ɵ���������Ƕ��٣������ڣ���������������������ڣ����-1�� 
*/
#include <cstdio>
#include <cstring>
#include <cmath>
typedef long long LL;
const int maxn = 15;
LL sum, a[maxn], max;
int n, t, m;
bool v[maxn];
bool prime(LL x)
{
	if(x < 2){
		return false;
	}
	int tmp = (int)sqrt(x);
	for(int i = 2; i <= tmp; i++){
		if(!(x % i)){
			return false;
		}
	}
	return true;
} 
long long dfs(int index)
{
	if(index == m){
		if(prime(sum)){
			max = max > sum ? max : sum;
			return max;
		}
		return max;
	}
	for(int i = 0; i < n; i++){
		if(!v[i]){
			sum += a[i];
			v[i] = true;
			dfs(index + 1);
			v[i] = false;
			sum -= a[i];
		}
	}
	return max;
}
int main()
{
	//freopen("�������.in","r", stdin);
	//freopen("�������.out","w", stdout);
	while(~scanf("%d", &t)){
		while(t--){
			memset(a, 0, sizeof(a));
			memset(v, 0, sizeof(v));
			sum = 0;
			max = -1;
			scanf("%d %d", &n, &m);
			for(int i = 0; i < n; i++){
				scanf("%lld", a + i);
			}
			printf("%lld\n", dfs(0));
		}
	}
	return 0;
}
