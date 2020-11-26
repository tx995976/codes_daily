#include <cstdio>
const int maxn = 1005;
int a[maxn], b[maxn], n;
void init()
{
	for(int i = 1; i < maxn; i++){
		a[i] = b[i] = i;
	}
}
void print()
{
	printf("%d", b[1]);
	for(int i = 2; i <= n; i++){
		printf(" %d", b[i]);
	}
	puts("");
}
void swap(int x, int y)
{
	int tmp1 = b[x], tmp = b[a[y]];
	b[a[y]] = b[x];
	b[x] = tmp;
	tmp = a[tmp1];
	a[tmp1] = a[y];
	a[y] = tmp;
	
}
int main()
{
	int t;
	//freopen("lxh打cf随机.in","r", stdin);
	//freopen("lxh打cf随机.out","w", stdout);
	while(~scanf("%d", &t)){
		while(t--){
			while(~scanf("%d", &n)){
				init();
				int s, s1, tmp, tmp1;
				for(int i = 1; i <= n; i++){
					scanf("%d %d", &s, &s1);
					int x = (a[i] + 1) % n ? (a[i] + 1) % n : n, x1 = (a[i] + 2) % n ? (a[i] + 2) % n : n;
					if((b[x] == s && b[x1] == s1) || (b[x] == s1 && b[x1] == s)){
						
					} else if(b[x] != s && b[x1] == s1){
						swap(x, s);
					} else if(b[x] == s && b[x1] != s1){
						swap(x1, s1);
					} else if(b[x] == s1 && b[x1] != s){
						swap(x1, s);
					} else if(b[x] != s1 && b[x1] == s){
						swap(x, s1);
					} else {
						swap(x, s);
						swap(x1, s1);
					}
					print();
				}
			}
		}
	}
	return 0;
}
