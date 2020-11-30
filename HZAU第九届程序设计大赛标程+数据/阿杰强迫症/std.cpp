#include <cstdio>

int a[10010];
int b[10010];
int c[10010];
int n;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &a[i]);
            c[i] = a[i];
        }
        for(int i=1; i<=n; i++)
            scanf("%d", &b[i]);
        for(int i=2; i<=n-1; i++)
        {
            if(a[i-1] != b[i-1])
            {
                a[i-1] = !a[i-1];
                a[i] = !a[i];
                a[i+1] = !a[i+1];
            }
        }
        if(a[n-1] != b[n-1])
        {
            a[n-1] = !a[n-1];
            a[n] = !a[n];
        }
        if(a[n] == b[n] && a[n-1] == b[n-1])
        {
            printf("yes\n");
            continue;
        }
        c[1] = !c[1], c[2] = !c[2];
        for(int i=2; i<=n-1; i++)
        {
            if(c[i-1] != b[i-1])
            {
                c[i-1] = !c[i-1];
                c[i] = !c[i];
                c[i+1] = !c[i+1];
            }
        }
        if(c[n-1] != b[n-1])
        {
            c[n-1] = !c[n-1];
            c[n] = !c[n];
        }
        if(c[n] == b[n] && c[n-1] == b[n-1])
        {
            printf("yes\n");
            continue;
        }
        printf("no\n");
    }
    return 0;
}


