/*
�������һ�ֽ���twt�Ĳ��������������ӣ���������Ҫ��������������������ӡ���֪��һ����ׯ��һ����n���ˣ���m���˱�ȷ����Ⱦ�ˣ��������ǲ�֪��
���Ǻ�˭�Ӵ�������֪�ò�����һ����Χ�ڲŻᴫ������������Ų飬���ǵõ��������������˽Ӵ����ľ����¼������������Ҫ֪���м���δ����Ⱦ�������������մ𰸡�
 ����
 ��һ��һ��������t������������ t��� = 10 
 ÿ�����ݵ�һ���������ÿո�����������������ׯ��n���ˣ���m�����ѱ���Ⱦ������������ΧΪk n,m,k���Ϊ1000
 ����ȥ�кܶ���(�������Ϊ10000)��ÿ���������ÿո���������� ����a��b�Ӵ��ľ���Ϊc    a,b���Ϊ1000,c���Ϊ10000��a������b
 ��a b c������0 ʱ������ȥһ����m���ÿո��������������������֪����Ⱦ���˵ı�ţ����Ϊ1-n�� 
���
 ÿ���������һ�а���һ������������δ����Ⱦ������  
*/
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 1005;
int e[maxn][maxn], vis[maxn], w[maxn];
void add(int a, int b, int c)
{
	if(e[a][b] > c){
		e[a][b] = e[b][a] = c;
	}
}
int main()
{
	//freopen("twt�������.in","r", stdin);
	//freopen("twt�������.out","w", stdout);
	int t, n, k, a, b, c, m, tmp, test1;
	while(~scanf("%d", &t)){
		while(t--){
			memset(vis, 0, sizeof(vis));
			memset(w, 0, sizeof(w));
			queue<int> q;
			memset(e, 0x7f, sizeof(e));
			scanf("%d %d %d", &n, &m, &k);
			while(scanf("%d %d %d", &a, &b, &c) && a && b && c){
				add(a, b, c);
			}
			int sum = n;
			for(int i = 0; i < m; i++){					
				scanf("%d", &tmp);
				w[tmp] = vis[tmp] = 1;  //��ǲ���
				q.push(tmp);
				sum--;					//��������
			}
			while(!q.empty()){
				tmp = q.front();
				q.pop();
				for(int i = 1; i <= n; i++){
					if(!vis[i] && !w[i]){
						//printf("%d %d\n", tmp, e[tmp][i]);
						if(e[tmp][i] <= k){   //����Я����������δ��Ⱦ������Ա�
							//printf("here\n");
							vis[i] = 1;
							w[i] = 1;
							q.push(i);  //����Ⱦ��������ջ
							sum--;
							test1++;
							printf("%d \n",tmp);
						}
					}
				}
				//printf("t:%d\n", sum);
			}
			printf("%d %d\n", sum,test1);
			
		}
	}				
	return 0;
 } 
