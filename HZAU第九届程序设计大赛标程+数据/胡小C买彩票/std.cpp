#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct lottery
{
    char in[10][5];
    int num[10];
};
lottery inf[10];
int flag[40];

void turn_to_num(int pos)
{
    for(int i = 1; i <= 7; i++)
    {
        inf[pos].num[i] = 0;
        inf[pos].num[i] += (inf[pos].in[i][0]-'0')*10;
        inf[pos].num[i] += inf[pos].in[i][1]-'0';
    }
}
int get_ans(int s,int m,int n)
{
    int ans = 0;
    for(int i = 1; i <= s; i++)
    {
        memset(flag,0,sizeof(flag));
        for(int j = 1; j <= 7; j++)
            flag[inf[0].num[j]]++;
        for(int j = 1; j <= 7; j++)
            flag[inf[i].num[j]]++;
        int sum = 0;
        for(int i = 1; i <= 33; i++)
        {
            if(flag[i]==2)
                sum++;
        }
        if(sum==7) ans += m;
        else if(sum==6) ans += n;
        else if(sum==5) ans += 150;
        else if(sum==4) ans += 10;
        else if(sum==3) ans += 5;
    }
    return ans;
}

int main()
{
    //freopen("test2.in","r",stdin);
    //freopen("test2.out","w",stdout);
    int t,m,n;
    cin>>t>>m>>n;
    for(int i = 1; i <= 7; i++)
        cin>>inf[0].in[i];
    turn_to_num(0);
    while(t--)
    {
        int s;
        cin>>s;
        //cout<<t<<"dd"<<endl;
        for(int i = 1; i <= s; i++)
        {
            for(int j = 1; j <= 7; j++)
                cin>>inf[i].in[j];
            turn_to_num(i);
        }
        int out = get_ans(s,m,n);
        cout<<out<<endl;
    }
    return 0;
}
