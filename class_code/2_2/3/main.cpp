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
    cout<<"请以下患者明日再来:"<<endl;
    pat_queue.visit(&queue_print);
    cout<<endl;
}

void queue_in(){
    std::string pat_in;
    cout<<"输入名字"<<endl;
    cin>>pat_in;
    pat_queue.push(pat_in);
    cout<<"您现在的队列位数:"<<pat_queue.size()<<endl;
}

void queue_next(){
    if(pat_queue.empty()){
        cout<<"无患者"<<endl;
        return;
    }
    std::string pat_next = pat_queue.pop();
    cout<<"请患者:"<<pat_next<<" 就诊"<<endl;
}

void menu(){
    int i;
    while(1){
        cout<<"输入操作:"<<endl
            <<"1.患者报到\n"
            <<"2.下一位患者就诊\n"
            <<"3.下班提醒\n"
            <<"0.退出\n";
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
