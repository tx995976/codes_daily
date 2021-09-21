#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a[20],last;
    int k=1,sum=0; scanf("%s",a);
    for(int i=0;i<=10;i++)
        if(a[i]!='-')
        {
            int t=a[i]-'0';
            sum+=t*k,k++;
        }
    sum=sum%11;
    if(sum==10) last='X';
    else last=sum+'0';
    if(last==a[12]) printf("Right");
    else a[12]=last,puts(a);
    return 0;
}