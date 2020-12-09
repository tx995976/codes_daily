#include<iostream>
#include<string>

using namespace std;

string a;
int n;

void pass(){
    for(int i = 0;i <= a.length();i++){
        if(a[i]>='a' && a[i]<='z'){
            a[i]+=n;
            if(a[i]<'a')
                a[i]+='z'-'a'+1;
            else if(a[i]>'z')
                a[i]-='z'-'a'+1;
        }
        else if(a[i]>='A' && a[i]<='Z'){
            a[i]+=n;
            if(a[i]<'A')
                a[i]+='Z'-'A'+1;
            else if(a[i]>'Z')
                a[i]-='Z'-'A'+1;
        }
    }
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    getline(cin,a);
    cin>>n;
    n=n%26;
    pass();
    cout<<a<<endl;
    return 0;
}