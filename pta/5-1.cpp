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
vector<num> fall;

//�жϣ����㺯��
double average_price(num a){
    return (a.a1+a.a2+a.a3+a.a4+a.a5)/5;
}

bool compare_price(num a,num b){
    return average_price(a) > average_price(b);
}

bool compare_date(num a,num b){
    return a.date[3] - '0' > b.date[3] - '0';
}
//

//���ܺ���
void num_read(){
    num temp;
    ifstream num_data;
    num_data.open("in.txt",ios::in|ios::out);
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

void num_write(){
    ofstream num_data("in.txt");
    ofstream fail("fall.txt");
    for(int i = 0;i < data_1.size();i++){
        num_data<<data_1[i].id<<"   "<<data_1[i].name<<"    "<<data_1[i].sex<<"      "<<data_1[i].date<<"      "<<data_1[i].tel<<"     "<<data_1[i].a1<<"   "<<data_1[i].a2<<"   "<<data_1[i].a3<<"   "<<data_1[i].a4<<"   "<<data_1[i].a5<<"   "<<endl;
        if(data_1[i].a1 < 60 || data_1[i].a2 < 60 || data_1[i].a3 < 60 || data_1[i].a4 < 60|| data_1[i].a5 < 60)
            fail<<data_1[i].id<<"   "<<data_1[i].name<<"    "<<data_1[i].sex<<"      "<<data_1[i].date<<"      "<<data_1[i].tel<<"     "<<data_1[i].a1<<"   "<<data_1[i].a2<<"   "<<data_1[i].a3<<"   "<<data_1[i].a4<<"   "<<data_1[i].a5<<"   "<<endl;
    }
    num_data.close();
    fail.close();
    data_1.clear();
}

void print_it(){
    cout<<"���  "<<"ѧ��           "<<"����    "<<"�Ա�    "<<"��������        "<<"�绰            "<<"���� "<<"��ѧ "<<"Ӣ�� "<<"���� "<<"���� "<<"ƽ����"<<endl;
        // 1.       100012400569      С��         ��          2001.09.21        18452261236        80       32      63      95       32
    for(int i = 0; i < data_1.size();i++)
        cout<<i+1<<".    "<<data_1[i].id<<"   "<<data_1[i].name<<"    "<<data_1[i].sex<<"      "<<data_1[i].date<<"      "<<data_1[i].tel<<"     "<<data_1[i].a1<<"   "<<data_1[i].a2<<"   "<<data_1[i].a3<<"   "<<data_1[i].a4<<"   "<<data_1[i].a5<<"   "<<average_price(data_1[i])<<endl;

}
void add(){
    int i = 1;
    cout<<"��ʼ¼��"<<endl;
    num temp;
    while(i){
        cin>>temp.id;
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
        cout<<"����0��������������"<<endl;
        cin>>i;
    }

}

void print_member(){
    int n;
    cout<<"ѡ�����򷽷���"<<endl<<" 1.��ƽ����"<<endl<<" 2.������"<<endl;
    cin>>n;
    switch(n){
        case 1:
            sort(data_1.begin(),data_1.end(),compare_price);
            break;
        case 2:
            sort(data_1.begin(),data_1.end(),compare_date);
            break;
    }
    print_it();
}
//

//������
void funtion1(){
    num_read();
    int n;
    while(1){
        cout<<"ѡ����:"<<endl<<"  1.¼��ɼ�"<<endl<<"  2.�鿴�ɼ�"<<endl<<"  3.�����޸Ĳ�������һ��"<<endl;
        cin>>n;
        switch(n){
            case 1:
                add();
                continue;
            case 2:
                print_member();
                continue;
            case 3:
                num_write();
                return;    
        }
    }
}

void funtion2(){
    string file,temp;
    int i = 1;
    cout<<"�����ļ�����"<<endl;
    cin>>file;
    ifstream file_1(file);
    if(!file_1)
        cout<<"error";
    while(!file_1.eof()){
        getline(file_1,temp);
        temp =" "+temp;
        cout<<i<<". "<<temp<<endl;
        i++;  
    }
}

int main(){
    int n;
    ios::sync_with_stdio(0);cin.tie(0);
    while(1){
        cout<<"ѡ������Ҫʹ�õĹ���:"<<endl<<"  1.ѧ���ɼ�¼�����ѯ"<<endl<<"  2.��ȡ�ļ�"<<endl<<"  3.�˳�"<<endl;
        cin>>n;
        switch(n){
            case 1:
                system("cls");
                funtion1();
                continue;
            case 2:
                system("cls");
                funtion2();
                continue;
            case 3:
                return 0;
            default:
                system("cls");
                cout<<"�޹��ܣ���������"<<endl;
                continue;
        }
    }
return 0;
}