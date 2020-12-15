#include<iostream>

using namespace std;

int num1_save;

int num2(int a,int b){
    return a*b / num1_save;
}

int num1(int a, int b){
    int mod_=1;
    if(a < b)
        swap(a,b);
    while(mod_ != 0){
        mod_ = a % b;
        a = b;
        b = mod_;
    }
    num1_save = a;
    return a;
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<num1(a,b)<<endl<<num2(a,b)<<endl;
    return 0;
}