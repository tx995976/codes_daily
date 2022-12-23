//#
//@
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

char gp[510][510];
bool rep = 0;

int main(){
    int h,w;
    scanf("%d %d", &h,&w);
    for(int i = 1;i <= h;i++)
        for(int j = 1;j <= w;j++)
            scanf(" %c",&gp[i][j]);

    int i=1,j=1;
    auto f = [&](){
        while(gp[i][j] != 'o'){
            rep = 0;
            char t = gp[i][j];
            gp[i][j] = 'o';
            switch(t){
                case 'R':
                    if(j == w)
                        return;
                    j += 1;
                    break;
                case 'L':
                    if(j == 1)
                        return;
                    j -= 1;
                    break;
                case 'U':
                    if(i == 1)
                        return;
                    i -= 1;
                    break;
                case 'D':
                    if(i == h)
                        return;
                    i += 1;
                    break;
            }
            rep = 1;
        }
    };
    f();
    if(rep)
        printf("-1\n");
    else
        printf("%d %d\n",i,j);
    return 0;
}