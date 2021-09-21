#include"calculator.hpp"

//////// + - * / ^
calculator_nums calculator_nums:: operator + (const calculator_nums &other){
    calculator_nums temp;
    temp.num = this->num + other.num;
    return temp;
} 
calculator_nums calculator_nums:: operator - (const calculator_nums &other){
    calculator_nums temp;
    temp.num = this->num - other.num;
    return temp;
}
calculator_nums calculator_nums:: operator * (const calculator_nums &other){
    calculator_nums temp;
    temp.num = this->num * other.num;
    return temp;
} 
calculator_nums calculator_nums:: operator / (const calculator_nums &other){
    calculator_nums temp;
    temp.num = this->num / other.num;
    return temp;
} 
calculator_nums calculator_nums:: operator ^ (const calculator_nums &other){
    calculator_nums temp;
    temp.num = pow(this->num,other.num);
    return temp;
}

void calculator_nums::num_sqrt(){
    this->num = sqrt(this->num);
}

void calculator_nums::show_result(){
    cout<<"result: "<<this->num<<endl;
}

//  优先级  * / || + -
////////////////////////////////////////////////////////////////////////////////////////////////

#define NUM_replace puncts.erase(puncts.begin()+punct1);\
            nums.erase(nums.begin()+num1);\
            nums.erase(nums.begin()+num1);\
            nums.insert(nums.begin()+num1,new_num);

calculator_nums calculate(vector<calculator_nums> &nums,vector<calculator_puncts> &puncts){
    int num1 = 0,punct1 = 0;
    calculator_nums new_num;
    for(auto i =puncts.begin();i+punct1 != puncts.end(); ){
        if(puncts[punct1].punct == '^'){
            new_num = nums[num1] ^ nums[num1+1];
            NUM_replace
        }
        else
            num1++,punct1++;
    }
    num1 = 0,punct1 = 0;
    for(auto i =puncts.begin();i+punct1 != puncts.end(); ){
        if(puncts[punct1].punct == '*'){
            new_num = nums[num1] * nums[num1+1]; 
            NUM_replace
        }
        else if(puncts[punct1].punct == '/'){
            new_num = nums[num1] / nums[num1+1]; 
            NUM_replace
        }
        else
            num1++,punct1++;
    }
    num1 = 0,punct1 = 0;
    for(auto i =puncts.begin();i+punct1 != puncts.end(); ){
        if(puncts[punct1].punct == '+'){
            new_num = nums[num1] + nums[num1+1]; 
            NUM_replace
        }
        else if(puncts[punct1].punct == '-'){
            new_num = nums[num1] - nums[num1+1]; 
            NUM_replace
        }
        else
            num1++,punct1++;
    }
    return nums.front();
}
////////////////////////////////////////////////////////////////////////////////////////////////

calculator_nums func_string_ready(stringstream &math_string){
    char temp;
    vector<calculator_nums> nums;
    vector<calculator_puncts> puncts;
    calculator_nums digit;
    if(math_string.peek() == '-'){
        math_string>>digit;
        nums.push_back(digit);
    }
    while(!math_string.eof()){
        temp = math_string.peek();
        if(isdigit(temp)){
            math_string >> digit;
            nums.push_back(digit);
        }
        else if(ispunct(temp)){
             if(temp == '('){
                math_string.get();
                nums.push_back(func_string_ready(math_string));
            }
            else if(temp == ')'){
                math_string.get();
                return calculate(nums,puncts);
            }
            else {
                calculator_puncts punct(math_string.get());
                puncts.push_back(punct);
            }
        }
        else if(isalpha(temp)){
            string punct_string;
            while(isalpha(math_string.peek())){
                punct_string.insert(punct_string.end(),math_string.get());
            }
            if(punct_string == "sqrt"){
                math_string.get();
                digit = func_string_ready(math_string);
                digit.num_sqrt();
            }
            nums.push_back(digit);
        }

    }
    return calculate(nums,puncts);
}


void input(){
    stringstream math_string;
    calculator_nums result;
    string test;
    getline(cin,test);
    test.erase(remove(test.begin(),test.end(),' '),test.end());
    math_string<<test;
    result = func_string_ready(math_string);
    result.show_result();
    return;
}