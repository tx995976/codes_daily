#include<iostream>
#include<string>

using namespace std;

string num;

int main(){
    cin>>num;
    cout<<num.length()<<endl;
    for(int i = num.length()-1;i >= 0;i--)
        cout<<num[i];
    cout<<endl;
    return 0;
}