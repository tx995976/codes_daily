#include<iostream>
#include<algorithm>
#include<cctype>
#include<string>
#include<sstream>
#include<list>
#include<vector>

using namespace std;

class  calculator_nums{
    protected:
        double num;
    public:
        calculator_nums(){}
        calculator_nums(double nums){this->num = nums;}
        ~calculator_nums(){}

        calculator_nums operator + (const calculator_nums &other); 
        calculator_nums operator - (const calculator_nums &other);
        calculator_nums operator * (const calculator_nums &other); 
        calculator_nums operator / (const calculator_nums &other); 
        calculator_nums operator ^ (const calculator_nums &other);


        friend void operator >> (ostream &out,calculator_nums &it){
            out>>it;
        }
        friend double calculate(vector<calculator_nums> &nums,vector<calculator_puncts> &puncts);
};

class calculator_puncts{
    protected:
        char punct;
    public:
        calculator_puncts(){}
        calculator_puncts(char puncts){this->punct = puncts;}
        ~calculator_puncts(){}
        
        friend void operator >> (ostream &out,calculator_puncts &it){
            out>>it;
        }
        friend double calculate(vector<calculator_nums> &nums,vector<calculator_puncts> &puncts);
};
