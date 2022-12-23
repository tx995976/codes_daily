#include <cstdio>
#include <cmath>

double r,h;
double res_area,res_perimeter,res_vol;
double pi = 3.14;

int main(){
    printf("input r,h:\n");
    scanf("%lf %lf",&r,&h);
    res_perimeter = r*2*pi;
    res_area = r*r*pi;
    res_vol = res_area*h;

    printf("area is %.2f\nperimeter is %.2f\nvol is %.2f\n",res_perimeter,res_area,res_vol);
}