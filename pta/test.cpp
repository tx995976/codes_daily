#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;

class num{
    public:
        string id;
        string name;
        string sex;
        string date;
        string tel;
        double a1;
        double a2;
        double a3;
        double a4;
        double a5;
};

vector<num> data_1;

void num_read(){
    string txt;
    num temp;
    ifstream num_data("D:\\vscodes\\pta\\in.txt");
    if(!num_data.is_open())
        cout<<"error"<<endl;
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
    data_1.erase(data_1.end());
    num_data.close();
}  

int main(){
    num_read();
        cout<<"序号  "<<"学号           "<<"姓名    "<<"性别    "<<"出生日期        "<<"电话            "<<"语文 "<<"数学 "<<"英语 "<<"理综 "<<"体育 "<<endl;
      // 1.       100012400569      小明         男          2001.09.21        18452261236        80       32      63      95       32
    for(int i = 0; i < data_1.size();i++){
        cout<<i+1<<".    "<<data_1[i].id<<"   "<<data_1[i].name<<"    "<<data_1[i].sex<<"      "<<data_1[i].date<<"      "<<data_1[i].tel<<"     "<<data_1[i].a1<<"   "<<data_1[i].a2<<"   "<<data_1[i].a3<<"   "<<data_1[i].a4<<"   "<<data_1[i].a5<<"   "<<endl;
        //cout<<"1.    "<<"100012400569   "<<"小明    "<<"男      "<<"2001.09.21      "<<"18408563321     "<<"80   "<<"32   "<<"63   "<<"95   "<<"60   "<<endl;
    }
    return 0;
}