#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

int t,t_s,judge_flag = 0;

std::string t_str;
struct stu{
    std::string name;
    int scope,i;
    stu(){}
    stu(std::string a,int b,int c){
        name = a;
        scope = b;
        i = c;
    }
};
std::vector<stu> judge_tab,exam;
bool cmp(const stu &l,const stu &r){
    return l.scope == r.scope ? l.i < r.i : l.scope > r.scope;
}

void solve(){
    std::sort(exam.begin(),exam.end(),cmp);
    auto it_e = exam.begin(),it_judge = judge_tab.begin();
    while(it_e != exam.end()){
        if(it_e->scope != it_judge->scope){
            judge_flag = 1;
            break;
        }
        else if(it_e->name.compare(it_judge->name))
            judge_flag = 2;
        it_e++,it_judge++;
    }
    switch(judge_flag){
        case 1:
            std::cout<<"Error\n";break;
        case 2:
            std::cout<<"Not Stable\n";break;
        case 0:
            std::cout<<"Right\n";break;
    }
    if(judge_flag){
        for(auto i :exam)
            std::cout<<i.name<<" "<<i.scope<<"\n";
    }
}

int main(){
    while(std::cin>>t){
        judge_tab.clear();
        exam.clear();
        judge_flag = 0;
        for(int i = 0;i < t;i++){
            std::cin>>t_str>>t_s;
            exam.push_back(stu(t_str,t_s,i));
        }
        for(int i = 0;i < t;i++){
            std::cin>>t_str>>t_s;
            judge_tab.push_back(stu(t_str,t_s,0));
        }
        solve();
    }
    return 0;
}