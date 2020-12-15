#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

string word;


int main(){
    getline(cin,word);
    word.erase(remove(word.begin(), word.end(),' '),word.end());
    cout<<word<<endl;
    return 0;
}