#include<iostream>
#include<string>

using namespace std;

string word;
int num,char_,pass,alpha;

int main(){
    getline(cin,word);
    for(int i = 0;i < word.length(); i++){
        if(word[i]>='0' && word[i] <= '9')
            num++;
        else if(word[i] == ' ')
            pass++;
        else if((word[i]>='a' && word[i] <='z')||(word[i]>='A' && word[i] <='Z'))
            char_++;
        else
            alpha++;
    }
    cout<<"数字："<<num<<endl<<"空格："<<pass<<endl<<"字母："<<char_<<endl<<"其他："<<alpha<<endl;
    return 0;
}