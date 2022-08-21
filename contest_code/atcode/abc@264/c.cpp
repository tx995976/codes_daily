//#
//@
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

int h1,w1,h2,w2;
int eh[11],ew[11];
int matix1[11][11],matix2[11][11];
bool flag = 0;

bool equal(){
    if(flag)
        return 1;
    int mati[11][11];
    for(int i = 1;i <= h2;i++){
        for(int j = 1;j <= w2;j++){
            mati[i][j] = matix1[eh[i]][ew[j]];
        }
    }
   
    for(int i = 1;i <= h2;i++)
        for(int j = 1;j <= w2;j++){
            if(mati[i][j] != matix2[i][j])
                return 0;
        }
    return flag = 1;
}

void dfsw(int w,int cntw){
    if(cntw == w2)
        equal();
    if(w > w1)
        return;
    dfsw(w+1,cntw);
    ew[cntw+1] = w;
    dfsw(w+1,cntw+1);
}

void dfsh(int h,int cnth){
    if(cnth == h2)
        dfsw(1,0);
    if(h > h1)
        return;
    dfsh(h+1,cnth);
    eh[cnth+1] = h;
    dfsh(h+1,cnth+1);
}


int main(){
    scanf("%d%d",&h1,&w1);
    for(int i = 1; i <= h1; i++)
        for(int j = 1; j <= w1; j++)
            scanf("%d",&matix1[i][j]);

    scanf("%d %d",&h2,&w2);
    for(int i = 1; i <= h2; i++)
        for(int j = 1; j <= w2; j++)
            scanf("%d",&matix2[i][j]);
   
    if(h2 > h1 || w2 > w1)
        flag = 0;
    else
        dfsh(1,0);
    printf("%s\n",flag ? "Yes" : "No");
    return 0;
}