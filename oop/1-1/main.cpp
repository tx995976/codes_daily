#include"test.hpp"
int main(){
        while(!login());
            cout<<"请重试"<<endl;
        int i;
        cout<<"欢迎使用网络计费系统"<<endl;
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
        while(1){
            cin>>i;
            switch(i){
                case 1:       
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
                    delete_card();
                    continue;  
                case 0:
                    return 0; 
                default:
                    cout<<"输入不符合要求"<<endl;
                    continue;
            }
        }
    }
