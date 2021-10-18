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
    {'(',3},
    {')',3}
};

void str_in(){
    std::getline(std::cin,input);
    //input.erase(remove(input.begin(),input.end(),' '),input.end());
}

void stack_punct(){


}

/////////////////////////////////////////////////////////////////////
int middle_back(){
    int temp_num;
    char temp_punct;
    input.erase(remove(input.begin(),input.end(),' '),input.end());
    math_str<<input;

    while(math_str.peek() != '='){
        if(isdigit(math_str.peek())){
            math_str>>temp_num;
            num_st.push(temp_num);
            continue;
        }
        if(ispunct(math_str.peek())){
            


        }
    }



}

int back_calculate(){




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

        case 2:

    }

}

int main(){
    using namespace std;
    return 0;
}