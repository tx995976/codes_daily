#include"member.hpp"
using itor_map = map<string,member>::iterator;
int login_if = 1;

void start(){
    int i,log = 0;
        while(!log){
            cout<<endl<<"��ӭʹ������Ʒ�ϵͳ"<<endl;
            cout<<"���ȵ�¼�򿪿�"<<endl
                <<"1.��¼"<<endl
                <<"2.��ӿ�"<<endl
                <<"3.�˳�"<<endl;
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
            cout<<"1.��ӿ�"<<endl
                <<"2.��ѯ��"<<endl
                <<"3.�ϻ�"<<endl
                <<"4.�»�"<<endl
                <<"5.��ֵ"<<endl
                <<"6.�˷�"<<endl
                <<"7.��ѯͳ��"<<endl
                <<"8.ע����"<<endl
                <<"0.�˳�"<<endl;
            cout<<"��������Ӧ���ܱ��"<<endl;
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
                    cout<<"���벻����Ҫ��"<<endl;
                    continue;
            }
        }
}

int main(){
    data_read();        //////////��ʼ��///////////
    while(login_if)
        start();
    return 0;
}
