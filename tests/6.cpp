#include <cstdio>
#include <cmath>

int a,b,c;

int main(){
    scanf("%d %d %d",&a,&b,&c);
    printf("max is %d\n",std::max(std::max(a,b),c));
}