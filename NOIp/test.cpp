#include<iostream>

void test(int a,int b){
    int a,b;
    std::cin>>a>>b;
    int c = a + b;
}
int test2(int a, int b){
    return 0;
}
int test3(int a, int b){
    if(a != b){
        return 0;
    }
    else return 1;

}


int main(){
    test2(1,3);
    test3(3,5);
    return 0;    
}