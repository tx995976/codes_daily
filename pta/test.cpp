#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;


int main(){
    int c = 4;
    int *a = &c;
    int *b = a;
    cout<<a<<" "<<b<<endl<<*a<<" "<<*b;
    return 0;
}