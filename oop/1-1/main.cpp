#include"test.hpp"
int main(){
        while(!login());
            cout<<"������"<<endl;
        int i;
        cout<<"��ӭʹ������Ʒ�ϵͳ"<<endl;
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
                    cout<<"���벻����Ҫ��"<<endl;
                    continue;
            }
        }
    }
