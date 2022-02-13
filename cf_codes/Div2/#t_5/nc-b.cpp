#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<deque>
#include<sstream>
#include<stack>

using namespace std;

class Solution {
public:
    long long legalExp(std::string str) {
        std::stack<long long> nums;
        std::stringstream ss(str);
        long long v_l,v_r,temp;
        char cal;
        ss.get();
        while(ss.peek() != '"'){
            if(isdigit(ss.peek())){
                ss>>temp;
                ss.get();
                nums.push(temp);
            }
            else{
                ss.get(cal);
                v_r = nums.top(); nums.pop();
                v_l = nums.top(); nums.pop();
                switch(cal){
                    case '+':
                        nums.push(v_l + v_r);
                        break;
                    case '-':
                        nums.push(v_l - v_r);
                        break;
                    case '*':
                        nums.push(v_l * v_r);
                        break;
                }
            }
        }
        return nums.top();
    }
};


int main(){
    string test;
    Solution tes;
    cin>>test;
    cout<<tes.legalExp(test)<<endl;
    return 0;
}