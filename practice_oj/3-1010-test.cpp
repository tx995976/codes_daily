#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN = 1e5 + 10;

int n;

struct Node
{
	int w, s;
	bool operator<(Node other) const
	{
		return w + s < other.w + other.s;  
	}
} nodes[MAXN];

int main()
{
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> nodes[i].w >> nodes[i].s;
		}
		sort(nodes, nodes + n);
		int ans = 0;
		int sum = 0;  
		for (int i = 0; i < n; i++)
		{
			ans = max(ans, sum - nodes[i].s < 0 ? 0 : sum - nodes[i].s);  
			sum += nodes[i].w;
		}
		cout << ans << endl;
	}
	return 0;
}