#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>


using namespace std;

class number{
    protected:
        string phone_num;
    public:
        friend void operator >>(istream &in,number &other);
        friend void operator <<(ostream &out,const number &other);

};


void operator >> (istream &in,number &other){
    in>>other.phone_num;
}

void operator <<(ostream &out,const number &other){
    out << other.phone_num;
}



int main(){
    number a;
    cin>>a;
    cout<<a;   
    return 0;
}