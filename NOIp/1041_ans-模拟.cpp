#include <iostream>
#include <algorithm>
using namespace std;
int n,p,t[309][309],a,b,d[309][309];
//n为人数。
//t为树。
//d为树的每一层的人。
bool f[309];
//f表示每个人是否被感染,0为感染,1为没感染。
void deep(int n,int k);
int clr(int n,bool k);
int get(int n,int ans);
int main()
{
    cin>>n>>p;
    for(int i=1;i<=p;i++){
        cin>>a>>b;
        if(a>b)
            swap(a,b);
        t[a][++t[a][0]]=b;
    }
    deep(1,1);
    cout<<get(2,n);
    return 0;
}

void deep(int n,int k)
{
    d[k][++d[k][0]]=n;
    if(!t[n][0])return;
    for(int i=1;i<=t[n][0];i++){
        deep(t[n][i],k+1);
    }
    return;
}
int clr(int n,bool k)
{
    //k=1为恢复感染。
    if(k)f[n]=0;
    else f[n]=1;
    if(!t[n][0])return 1;
    int ans=1;
    for(int i=1;i<=t[n][0];i++){
        ans+=clr(t[n][i],k);
    }
    return ans;
}
int get(int n,int ans)
{
    if(!d[n][0])return ans;
    int g=1000000,tmp;
    bool q=0;
    for(int i=1;i<=d[n][0];i++){
        if(f[d[n][i]])continue;
        //如果这个点没被感染。
        q=1;
		//如果这层还可以继续传播标记q为1。
        tmp=clr(d[n][i],0);
        //切断点n与上一个点的链接。
		//标记n的子树为未感染状态。
		//tmp表示这个点的子树大小。
        g=min(get(n+1,ans-tmp),g);
        //继续传播。
        clr(d[n][i],1);
        //恢复链接。
		//标记n的子树为感染
    }
    if(!q)return ans;
	//如果这层为空，那么答案就是现在感染的人数
    return g;
}