#include<iostream>
#include<sstream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

class number{
    protected:
        string phone_num;
        string region_num;
    public:
        friend void operator >>(istream &in,number &other);
        friend void operator <<(ostream &out,const number &other);

};


void operator >> (istream &in,number &other){
    string a2;
    in>>a2;
    stringstream phone;
    a2.erase(remove(a2.begin(),a2.end(),' '),a2.end());
    replace(a2.begin(),a2.end(),'(',' ');
    replace(a2.begin(),a2.end(),')',' ');
    phone<<a2; 
    phone>>other.region_num>>other.phone_num;
}

void operator <<(ostream &out,const number &other){
    out <<"("<<other.region_num<<")"<< other.phone_num<<endl;
}

int main(){
    number a;
    cin>>a;
    cout<<a;   
    return 0;
}