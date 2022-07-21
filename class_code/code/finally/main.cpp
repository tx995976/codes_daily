#include"calculator.hpp"

void menu(){
    bool i = 1;
    cout<<"说明:"<<endl
        <<"支持 + - * / 及 ^(幂运算) 及sqrt()"<<endl;
        system("pause");
    while(i){
        cout<<"输入表达式进行计算: ";
        input();
        cout<<"输入1继续,0退出"<<endl;
        cin>>i;
        cin.ignore();
    }
}

int main(){
    system("chcp 65001");
    menu();
}