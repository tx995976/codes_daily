#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
short io;
int main(void)  
{
    char word1 = 'a';
    int64_t number = 23;
    printf("now, we will change zhe data type\n ");
    getchar();
    printf("zhe %c's number is %d\n ",word1,word1);
    getchar();
    printf("number = %" PRId32 " \n",number);
    scanf("%d" ,&io);
    printf("the io's twice is %d",io*2);
    return 0;
}
