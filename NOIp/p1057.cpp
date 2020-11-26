#include<bits/stdc++.h>
using namespace std;
int ball[40][31];
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m;
	cin>>n>>m;
	ball[0][1]=1;
	for(int i = 1;i<=m;i++){
		for(int k = 1;k<=n;k++){
			if(k==1)
				ball[i][k]=ball[i-1][n]+ball[i-1][2];
			else if(k==n)
				ball[i][k]=ball[i-1][n-1]+ball[i-1][1];
			else
				ball[i][k]=ball[i-1][k-1]+ball[i-1][k+1];
		}
	}
	cout<<ball[m][1]<<endl;
	return 0;
}