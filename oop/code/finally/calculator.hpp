#include<iostream>
#include<algorithm>
#include<cmath>
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
        void show_result();
        void num_sqrt();
        calculator_nums operator + (const calculator_nums &other); 
        calculator_nums operator - (const calculator_nums &other);
        calculator_nums operator * (const calculator_nums &other); 
        calculator_nums operator / (const calculator_nums &other); 
        calculator_nums operator ^ (const calculator_nums &other);


        friend void operator >> (stringstream &in,calculator_nums &it){
            in>>it.num;
        }
        friend void operator << (stringstream &out,calculator_nums &it){
            out<<it.num;
        }
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
        friend calculator_nums calculate(vector<calculator_nums> &nums,vector<calculator_puncts> &puncts);
};

extern void input();