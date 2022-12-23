#include<cstdio>
#include<cmath>

double r = 0.07,p = 0;
int n = 10;

int main(){
    p = std::pow((r+1.0),n);
    printf("%.2f\n",p);
    return 0;
}