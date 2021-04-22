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
    double perimeter(){
        return (this->length + this->wide)*2;
    }
    double Area(){
        return (this->length * this->wide);
    }
};

int main(){
    test a(20,50),b(3.6,4.5);
    cout<<a.perimeter()<<"  "<<a.Area()<<endl;
    cout<<b.perimeter()<<"  "<<b.Area()<<endl;
    return 0;
}