#include<iostream>
#include<algorithm>
#include<cctype>
#include<string>
#include<sstream>
#include<list>
#include<vector>

using namespace std;

stringstream math_string;


class  calculator_nums{
    protected:
        double num;
    public:
        calculator_nums(){}
        calculator_nums(double nums){this->num = nums;}
        ~calculator_nums(){}

        friend void operator >> (ostream &out,calculator_nums &it){
            out>>it;
        }

};

class calculator_puncts{
    protected:
        char punct;
    public:
        calculator_puncts(){}
        calculator_puncts(char puncts){this->punct = puncts;}
        ~calculator_puncts(){}

};

void calculate(){}

void ready(stringstream &math_string){
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


int main(){
    string a2;
    getline(cin,a2);
    a2.erase(remove(a2.begin(),a2.end(),' '),a2.end());
    math_string<<a2;
    ready(math_string);
    return 0;
}