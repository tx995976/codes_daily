#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>

using namespace std;

class student{
    protected:
        string id;
        string name;
        double scope;
    public:
        ~student(){}
        student(){}
        student(string id,string name,double scope){
            this->id = id;
            this->name = name;
            this->scope = scope;
        }
        friend void operator << (ostream &out,const student &other ){
            out<<other.id<<"       "<<other.name<<"            "<<other.scope<<endl;
        }
        friend void filein();
        friend void filewt();
        friend void data_input();
        friend void data_out();
};

map<string,student> data_map;
using data_map_itor = map<string,student>::iterator;

void filein(){
    student temp;
    ifstream data_in("data.dat",ios::in|ios::binary);
    while(data_in.read((char*)&temp,sizeof(temp))){
        data_map[temp.name] = temp;
    }
    data_in.close();
}

void filewt(){
    student temp;
    ofstream data_out("data.dat",ios::out|ios::binary);
    for(auto i = data_map.begin();i != data_map.end();i++){
        temp = i->second;
        data_out.write((char *)&temp,sizeof(temp));
    }
    data_out.close();
}

//////////////////////////////////////////////////////


//////////////////////////////////////////////////////

void data_input(){
    student temp;   
    int i = 1; 
    while(i){
        cout<<"输入数据:"<<endl;
        cin>>temp.id>>temp.name>>temp.scope;
        data_map[temp.id] = temp;
        cout<<"按1继续输入,0退出"<<endl;
        cin>>i;
    }
}

#define scope_tab cout<<"学号"<<"       "<<"姓名"<<"       "<<"成绩"<<endl;

void data_out(){
    int i = 0;
    data_map_itor review_page,page = data_map.begin();
    while(1){
        review_page = page;
        scope_tab;
        for(int i = 1;page!=data_map.end() && i <=10;i++){
            cout<<page->second;
            page++;
        }
        cout<<"1.上一页 "<<"2.下一页"<<"3.退出"<<endl;
        cin>>i;
        switch(i){
            case 1:
                page = review_page;
                break;
            case 2:
                break;
            case 3:
                return;
            default:
                return;
        }
    }
}

void data_search(){
    








}

void menu(){
    cout<<"选择功能"<<endl
        <<"1.输入数据"<<endl
        <<"2.输出数据"<<endl
        <<"3.按姓名查找数据"<<endl;
    int i;
    while(1){
        cin>>i;
        switch(i){
            case 1:
                data_input();
                break;
            case 2:
                data_out();
                break;
            case 3:
                data_search();
                return;           
            default:
                filewt();
                return;
        }
    }
}

int main(){
    filein();
    menu();
    return 0;
}

