#include<iostream>
#include<stack>

std::stack<char> train_queue;

void rebuild_queue(std::string &input){
    auto itor = input.begin();
    while(itor != input.end()){
        if(*itor == 'S')
            std::cout<<'S';
        else if(*itor == 'H')
            train_queue.push(*itor);
        else{
            std::cerr<<"invaild_input"<<std::endl;
            return;
        }
        itor++;
    }
    while(!train_queue.empty()){
        std::cout<<train_queue.top();
        train_queue.pop();
    }
    return;
}

int main(){
    using namespace std;
    string input;
    cin>>input;
    rebuild_queue(input);
    return 0;
}