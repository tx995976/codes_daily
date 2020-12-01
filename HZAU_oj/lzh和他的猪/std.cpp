#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1005;
int cnt[maxn];
bool pm[maxn];
void init()
{
    for(int i=2;i<maxn;i++)
    {
        if(!pm[i])
        {
            for(int j=i*2;j<maxn;j+=i)
            {
                pm[j]=true;
            }
        }
    }
    for(int i=2;i<maxn;i++) cnt[i]=cnt[i-1]+!pm[i];
}
int main()
{
    int t,n;
    init();
    //ifstream in("input.in");
    //ofstream out("out1.txt");
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<cnt[n]+1<<endl;
    }
    return 0;
}
