#include<iostream>
using namespace std;
class test{
    double length;
    double wide;
    public:
    test(double a,double b){
        length = a;
        wide = b;
    }
    ~test(){}
    double func_1(){
        return this->length + this->wide;
    }
    double func_2(){
        return this->length * this->wide;
    }
};

int main(){
    test a(20,50),b(3.6,4.5);
    cout<<a.func_1()<<"  "<<a.func_2()<<endl;
    cout<<b.func_1()<<"  "<<b.func_2()<<endl;
    return 0;
}