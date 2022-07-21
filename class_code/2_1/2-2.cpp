#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>

std::queue<char> input_queue;
std::stack<char> input_stack;

void char_push(std::string &input){
    auto itor_string = input.begin();
    while(*itor_string != '@' || itor_string == input.end()){
        input_queue.push(*itor_string);
        input_stack.push(*itor_string);
        itor_string++;
    }
    return;
}

bool char_check(){
    while(!input_stack.empty()){
        if(input_queue.front() == input_stack.top()){
            input_stack.pop();
            input_queue.pop();
        }
        else
            return 1;    
    }
    return 0;
}

int main(){
    using namespace std;
    string input;
    cin>>input;
    char_push(input);
    if(char_check())
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
    return 0;
}