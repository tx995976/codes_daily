#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string a[10];

bool compare(string a,string b){
    int c = 0;
    while(a[c] != b[c])
        c++;
    return int(a[c]) < int(b[c]);
}

int main(){
    for(int i = 0;i < 10;i++)
        getline(cin,a[i]);
    sort(a,a+10,compare);
    for(int i = 0;i < 10; i++)
        cout<<a[i]<<endl;
    return 0;
}