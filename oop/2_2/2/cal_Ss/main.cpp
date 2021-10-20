#include<iostream>
#include<algorithm>
#include<sstream>
#include<map>
#include"Sq_stack.hpp"

Sqstack<int> num_st;
Sqstack<char> punct_st;

std::string input;
std::stringstream math_str;

std::map<char,int> up_level = {
    {'+',1},
    {'-',1},
    {'/',2},
    {'*',2},
    {'(',0},
    {')',0}
};

void str_in(){
    std::getline(std::cin,input);
    //input.erase(remove(input.begin(),input.end(),' '),input.end());
}

int get_result(int num_l,int num_r,char punct){
    if(punct == '+')
        return num_l + num_r;
    else if(punct == '-')
        return num_l - num_r;
    else if(punct == '*')
        return num_l * num_r;
    else if(punct == '/')
        return num_l / num_r;
    return 0;
}

/////////////////////////////////////////////////////////////////////
int middle_back(){
    int temp_num;
    char temp_punct;
    str_in();
    input.erase(remove(input.begin(),input.end(),' '),input.end());
    math_str<<input;

    while(math_str.peek() != '='){
        if(isdigit(math_str.peek())){
            math_str>>temp_num;
            std::cout<<temp_num<<" ";
            continue;
        }

        if(ispunct(math_str.peek())){

            if(math_str.peek() == ')'){
                while(punct_st.Top() != '('){
                    punct_st.pop(temp_punct);
                    std::cout<<temp_punct<<" ";
                }
                punct_st.pop(temp_punct);
                continue;
            }

            if(math_str.peek() == '('){
                math_str.get(temp_punct);
                punct_st.push(temp_punct);
                continue;
            }
            //////////////////////////////////////
            if(punct_st.Top() == '(' || punct_st.empty()){
                math_str>>temp_num;
                num_st.push(temp_num);
                continue;
            }

            if(punct_st.empty() || up_level[punct_st.Top()] < up_level[math_str.peek()]){
                math_str.get(temp_punct);
                punct_st.push(temp_punct);
                continue;
            }

            else{
                char temp;
                math_str.get(temp_punct);
                while(!punct_st.empty() && up_level[punct_st.Top()] >= up_level[temp_punct]){
                        punct_st.pop(temp);
                        std::cout<<temp<<" ";
                }
                punct_st.push(temp_punct);
            }
        }
    }
    while(!punct_st.empty()){
        punct_st.pop(temp_punct);
        std::cout<<temp_punct<<" ";
    }
    return 0;
}

int back_calculate(){
    str_in();
    int num_l,num_r,temp_num;
    char temp_punct;
    std::stringstream math_str;
    while(!math_str.eof()){
        while(math_str.peek() == ' ')
            math_str.get();
        if(isdigit(math_str.peek())){
            math_str>>temp_num;
            num_st.push(temp_num);
            continue;
        }
        if(ispunct(math_str.peek())){
            math_str.get(temp_punct);
            num_st.pop(num_r);
            num_st.pop(num_l);
            temp_num = get_result(num_l,num_r,temp_punct);
            num_st.push(temp_num);
            continue;
        }
    }
    num_st.pop(temp_num);
    return temp_num;
}



void menu(){
    std::cout<<"输入序号"<<std::endl
             <<"1.中缀转后缀"<<std::endl
             <<"2.计算后缀"<<std::endl;
    int i;
    std::cin>>i;
    std::cin.ignore();
    switch(i){
        case 1:
            std::cout<<""<<std::endl;
            middle_back();
        case 2:
            back_calculate();
    }

}

int main(){
    using namespace std;
    return 0;
}
