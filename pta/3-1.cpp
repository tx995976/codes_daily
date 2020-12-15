#include<iostream>
#include<cmath>
using namespace std;

int pow_int (int a,int b){
    return pow(a,b);
}

int main(){
    int x,y;
    cin>>x>>y;
    cout<<pow_int(x,y)<<endl;
    return 0;
}