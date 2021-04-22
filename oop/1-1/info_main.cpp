#include"data_info.hpp"
#include"member.hpp"

void user_info_welcome(){
    system("cls");
    int i = 0;
    while(1){
        cout<<"用户数据记录"<<endl;
        cout<<"1.上机记录"<<endl
            <<"2.下机记录"<<endl
            <<"3.卡信息记录"<<endl
            <<"4.消费记录"<<endl
            <<"5.退出"<<endl<<endl;
        cin>>i;
        switch(i){
            case 1:
                user_record_online();
                break;            
            case 2:
                user_record_offline();
                break;            
            case 3:
                user_card_info();
                break;            
            case 4:
                user_record_cost();
                break;            
            case 5:
                return;                            
        }
    }
    
}

void admin_info_welcome(){
    system("cls");
    int i = 0;
    while(1){
        cout<<"管理员管理模式"<<endl;
        cout<<"1.id精准查询"<<endl
            <<"2.id模糊查询"<<endl
            <<"3.列出所有用户"<<endl
            <<"4.删除卡"<<endl
            <<"5.退出"<<endl<<endl;
        cin>>i;
        switch(i){
            case 1:
                break;            
            case 2:
                break;            
            case 3:
                break;            
            case 4:
                break;            
            case 5:
               return;
        }
    }
}
















