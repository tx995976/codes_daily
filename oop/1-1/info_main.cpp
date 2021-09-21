#include"data_info.hpp"
#include"member.hpp"

void user_info_welcome(){
    system("cls");
    int i = 0;
    while(1){
        cout<<"用户数据记录"<<endl;
        cout<<"1.卡信息记录"<<endl
            <<"2.消费记录"<<endl
            <<"3.充值退费记录"<<endl
            <<"4.退出"<<endl<<endl;
        cin>>i;
        switch(i){
            case 1:
                user_card_info();
                break;            
            case 2:
                user_record_cost();
                break;                     
            case 3:
                user_info_add_money();
                break;            
            case 4:
                return;                            
        }
        cout<<endl;
    }    
}

void admin_info_welcome(){
    income_data_load();
    system("cls");
    int i = 0;
    while(1){
        cout<<"管理员管理模式"<<endl;
        cout<<"1.id精准查询"<<endl
            <<"2.id模糊查询"<<endl
            <<"3.列出所有用户"<<endl
            <<"4.营业额查询"<<endl
            <<"5.退出"<<endl<<endl;
        cin>>i;
        switch(i){
            case 1:
                admin_search_id();
                break;            
            case 2:
                admin_search_non();
                break;            
            case 3:
                admin_list_users();
                break;            
            case 4:
                admin_total_money();
                break;      
            case 5:
               return;
        }
    }
}
















