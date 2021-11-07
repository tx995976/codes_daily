#include"L_queue.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include<regex>

using std::cin;
using std::cout;
using std::endl;


my_queue::Lq_queue<std::string> pat_queue;

void queue_print(std::string &in){
    cout<<in<<" ";
}

void queue_clear(){
    cout<<"�����»�����������:"<<endl;
    pat_queue.visit(&queue_print);
    cout<<endl;
}

void queue_in(){
    std::string pat_in;
    cout<<"��������"<<endl;
    cin>>pat_in;
    pat_queue.push(pat_in);
    cout<<"�����ڵĶ���λ��:"<<pat_queue.size()<<endl;
}

void queue_next(){
    if(pat_queue.empty()){
        cout<<"�޻���"<<endl;
        return;
    }
    std::string pat_next = pat_queue.pop();
    cout<<"�뻼��:"<<pat_next<<" ����"<<endl;
}

void menu(){
    int i;
    while(1){
        cout<<"�������:"<<endl
            <<"1.���߱���\n"
            <<"2.��һλ���߾���\n"
            <<"3.�°�����\n"
            <<"0.�˳�\n";
        cin>>i;
        switch(i){
            case 1 :{
                queue_in();
                break;
            }
            case 2 :{
                queue_next();
                break;
            }
            case 3 :{
                queue_clear();
                break;
            }
             case 0 :{
                 return;
            }
        }
    }
}

int main(){
    menu();
    return 0;
}
