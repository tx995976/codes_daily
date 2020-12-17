#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>

using namespace std;

class num{
    public:
        int id;
        string name;
        string sex;
        string date;
        long tel;
        double a1;
        double a2;
        double a3;
        double a4;
        double a5;
};

vector<num> data_1;

double average_price(num a){
    return (a.a1+a.a2+a.a3+a.a4+a.a5)/5;
}

bool compare_price(num a,num b){
    return average_price(a) > average_price(b);
}

bool compare_date(num a,num b){
    return a.date[3] - '0' > b.date[3] - '0';
}

void num_read(){
    num temp;
    ifstream num_data;
    num_data.open("data.txt",ios::in|ios::out);
    while(!num_data.eof()){
        num_data>>temp.id;
        num_data>>temp.name;
        num_data>>temp.sex;
        num_data>>temp.date;
        num_data>>temp.tel;
        num_data>>temp.a1;
        num_data>>temp.a2;
        num_data>>temp.a3;
        num_data>>temp.a4;
        num_data>>temp.a5;
        data_1.push_back(temp);
    }
    num_data.close();
}

void num_write(){
    ofstream num_data;
    num_data.open("data.txt");
    for(int i = 0;i < data_1.size();i++){
        num_data<<data_1[i].id;
        num_data<<data_1[i].name;
        num_data<<data_1[i].sex;
        num_data<<data_1[i].date;
        num_data<<data_1[i].tel;
        num_data<<data_1[i].a1;
        num_data<<data_1[i].a2;
        num_data<<data_1[i].a3;
        num_data<<data_1[i].a4;
        num_data<<data_1[i].a5;
    }
    num_data.close();
    data_1.clear();
}

void print_it(){

    
}

void add(){
    cout<<"开始录入，输入完整数据后输入 ^z 结束"<<endl;
    num temp;
    while(cin>>temp.id){
        cin>>temp.name;
        cin>>temp.sex;
        cin>>temp.date;
        cin>>temp.tel;
        cin>>temp.a1;
        cin>>temp.a2;
        cin>>temp.a3;
        cin>>temp.a4;
        cin>>temp.a5;
        data_1.push_back(temp);
    }
}

void print_member(){
    int n;
    cout<<"选择排序方法："<<endl<<" 1.按平均分"<<endl<<" 2.按年龄"<<endl;
    cin>>n;
    switch(n){
        case 1:
            sort(data_1.begin(),data_1.end(),compare_price);
            break;
        case 2:
            sort(data_1.begin(),data_1.end(),compare_date);
            break;
    }

}

void funtion1(){
    int n;
    cout<<"选择功能:"<<endl<<"  1.录入成绩"<<endl<<"  2.查看成绩"<<endl<<"  3.返回上一级";
    cin>>n;
    while(1){
        switch(n){
            case 1:
                add();
                continue;
            case 2:

                continue;
            case 3:
                break;    
        }
    }
}

int main(){
    int n;
    ios::sync_with_stdio(0);cin.tie(0);
    cout<<"选择你需要使用的功能:"<<endl<<"  1.学生成绩录入与查询"<<endl<<"  2.读取文件"<<endl<<"  3.退出";
    while(1){
        cin>>n;
        switch(n){
            case 1:
                funtion1();
                continue;
            case 2:

                continue;
            case 3:
                break;
            default:
                cout<<"无功能，重新输入"<<endl;
                continue;
        }
    }
return 0;
}