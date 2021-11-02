#include"L_queue.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;


my_queue::Lq_queue<std::string> pat_queue;

void queue_print(std::string &in){
    cout<<in<<" ";
}

void queue_clear(){
    cout<<" "<<endl;
    pat_queue.visit(queue_print);
}

void queue_in(){
    std::string pat_in;
    cout<<" "<<endl;
    cin>>pat_in;
    pat_queue.push(pat_in);
    cout<<" "<<pat_queue.size()<<endl;
}

void queue_next(){
    if(pat_queue.empty()){
        cout<<" "<<endl;
        return;
    }
    std::string pat_next = pat_queue.pop();
    cout<<" "<<pat_next<<endl;
}

void menu(){
    int i;
    cout<<" "<<endl;
    cin>>i;
    while(1)
        switch(i){
            case 1 :{
                queue_in();
                break;;
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

int main(){
    std::system("chcp 65001");
    menu();
    return 0;
}
