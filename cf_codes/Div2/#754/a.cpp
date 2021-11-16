#include<iostream>
int main(){
    int a1,a2,a3,t,t_p;
    scanf("%d",&t);
    while(t-- > 0){
        std::scanf("%d %d %d",&a1,&a2,&a3);
        t_p = (a1+a2+a3)%3;
        std::printf("%d\n",t_p == 0 ? 0:1);
    }

}