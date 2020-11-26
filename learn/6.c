#include<stdio.h>
#include<_cygwin.h>
int main(void){
    float weight;
    float vaule;
    short end = 111;
    printf("are you worth your weight?\n");
    printf("Let's check it out. \n");
    printf("Please enter your weight in platinum?\n");
    getchar();
    getchar();
    scanf("%f", &weight);
    vaule=1700*weight*14.5833;
    printf("Your weight in platinum is worth $%.2f\n",vaule);
    printf("You are easily worth that! If platinum price ");
    printf("eat more to maintain your value.\n");
    return 0;    
}


