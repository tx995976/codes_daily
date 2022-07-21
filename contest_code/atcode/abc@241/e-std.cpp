#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n;
	long long k;
	long long A[200010];
	long long S[200010];
	int pre[200010];
	int s, t, p, b;
	long long a, X;
	long long ans;

	cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> A[i];

	for (int i = 0; i < n; i++)pre[i] = -1;
	S[0] = 0;
	pre[0] = 0;

	for (int i = 0; i < n; i++) {
		S[i + 1] = S[i] + A[S[i] % n];
		if (pre[S[i + 1] % n] != -1) {
			s = pre[S[i + 1] % n];
			t = i + 1;
			break;
		}
		pre[S[i + 1] % n] = i + 1;
	}

	if (k <= s)ans = S[k];
	else {
		p = t - s;
		X = S[t] - S[s];
		a = (k - s - 1) / p;
		b = (k - s - 1) % p;
		ans = S[s + b + 1] + (a*X);
	}

	cout << ans << endl;
	return 0;
}
