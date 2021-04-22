#include"calculator.hpp"

stringstream math_string;

calculator_nums calculator_nums:: operator + (const calculator_nums &other){} 
calculator_nums calculator_nums:: operator - (const calculator_nums &other){}
calculator_nums calculator_nums:: operator * (const calculator_nums &other){} 
calculator_nums calculator_nums:: operator / (const calculator_nums &other){} 
calculator_nums calculator_nums:: operator ^ (const calculator_nums &other){}







//////// + - * / ^
double calculate(vector<calculator_nums> &nums,vector<calculator_puncts> &puncts){
    while(nums.size() != 1){

        






    }
}

void func_string_ready(stringstream &math_string){
    char temp;
    vector<calculator_nums> nums;
    vector<calculator_puncts> puncts;
    while(!math_string.eof()){
        temp = math_string.peek();
        if(isdigit(temp)){
            calculator_nums digit;
            math_string >> digit;
            nums.push_back(digit);
        }
        else if(ispunct(temp)){
            calculator_puncts punct(math_string.get());
            puncts.push_back(punct);
        }
        else if(isalpha(temp)){

        }

    }

}
