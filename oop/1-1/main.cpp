#include"member.hpp"
using itor_map = map<string,member>::iterator;
int login_if = 1;

void start(){
    int i,log = 0;
        while(!log){
            cout<<endl<<"欢迎使用网络计费系统"<<endl;
            cout<<"请先登录或开卡"<<endl
                <<"1.登录"<<endl
                <<"2.添加卡"<<endl
                <<"3.退出"<<endl;
            cin>>i;
            switch(i){
                case 1:
                    login();
                    log = 1;
                    break;
                case 2:
                    add_card();
                    break;
                case 3: 
                    data_write();
                    login_if = 0;
                    return;
            }
        }
        ////////////////////////////////////////////////////////////////////////////////////
        system("cls");
        while(1){
            cout<<endl;
            welcome();
            cout<<"1.添加卡"<<endl
                <<"2.查询卡"<<endl
                <<"3.上机"<<endl
                <<"4.下机"<<endl
                <<"5.充值"<<endl
                <<"6.退费"<<endl
                <<"7.查询统计"<<endl
                <<"8.注销卡"<<endl
                <<"0.退出"<<endl;
            cout<<"请输入相应功能编号"<<endl;
            cin>>i;
            switch(i){
                case 1:       
                    system("cls");
                    add_card();         
                    continue;   
                case 2:
                    query_card();
                    continue;  
                case 3:
                    start_up();
                    continue;  
                case 4:
                    shut_down();
                    continue;  
                case 5:
                     add_money();
                    continue;   
                case 6:
                    return_money();
                    continue;   
                case 7:
                    count_sys();
                    continue;  
                case 8:
                    system("cls");
                    if(delete_card())
                        return;
                    continue;  
                case 0:
                    data_write();
                    return; 
                default:
                    cout<<"输入不符合要求"<<endl;
                    continue;
            }
        }
}

int main(){
    data_read();        //////////初始化///////////
    while(login_if)
        start();
    return 0;
}
