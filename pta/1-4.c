#include<stdio.h>
int main(){
    double oil,a,b,c;
    int type;
    char discount;
    scanf("%lf %d %c",&oil,&type,&discount);
    switch(type){
        case 89:
            a = 5.5;    break;
        case 92:
            a = 7.14;   break;
        case 95:
            a = 7.64;   break;
    }
    if(discount == 'm')
        b = 0.95;
    else    
        b = 0.97;
    printf("%.2f$\n",a*b*oil);
    return 0;
}