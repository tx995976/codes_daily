#include<iostream>
#include<cstring>

using namespace std;

int countdigit (string number,int a){
    int total;
    for(int i = 0;i < number.length();i++){
        if(number[i]-'0' == a)
        total++;
    }
    return total;
}

int main(){
    string number;
    int a;
    cin>>number>>a;
    cout<<countdigit(number,a)<<endl;
    return 0;
}