#include"member.hpp"

using itor_map = map<string,member>::iterator;
map<string,member> data_tree;                  ///////////������
itor_map now_contrl;
int i;

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


void login(){
    string a,b;
    system("cls");
    cout<<"id:";
    cin>>a;
    itor_map temp = data_tree.find(a);
    while(temp == data_tree.end()){
        cout<<"id������,������"<<endl<<"id:";
        cin>>a;
        temp = data_tree.find(a);
    }
    cout<<"password:";
    cin>>b;
    while(!(temp->second.match_password(b))){
        cout<<"�������������"<<endl<<"password:";
        cin>>b;
    }
    now_contrl = temp;
}

void welcome(){
    cout<<"��ӭ:"<<now_contrl->second.show_name()<<endl;
}


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void query_card(){
        string status;
        if(now_contrl->second.status == 1)
            status = "online";
        else
            status ="offline";    
        cout<<"��ǰ�û�:"<<now_contrl->second.show_name()<<"     ���:"<<now_contrl->second.show_money()<<endl
            <<"״̬: "<<status<<endl;
        return;
}

void add_card(){
         string temp,temp1,temp3;
         double temp2;
         cout<<"�����������: ";
         cin>>temp;
         cout<<"�������id: ";
         cin>>temp3;
         cout<<"�����������: ";
         cin>>temp1;
         cout<<"������Ŀ������: ";
         cin>>temp2;
         member new_card(temp3,temp1,temp,temp2);
         data_tree[temp3] = new_card;
         cout<<"ע�������"<<endl;
         return;
     }

    bool delete_card(){
        string b;
        cout<<"password:";
        cin>>b;
        while(!(now_contrl->second.match_password(b))){
            cout<<"�������������"<<endl<<"password:";
            cin>>b;
        }
        cout<<now_contrl->second.show_name()<<" ��ȷ��Ҫ�˿���?"<<endl<<"1.��      2.��"<<endl;
        cin>>i;
        if(i){
            cout<<"�˿������"<<endl
                <<"����:"<<now_contrl->second.show_name()<<"        "<<"���:"<<now_contrl->second.show_money()<<endl;
            data_tree.erase(now_contrl);
            return 1;
        }
        return 0;
     }



//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void data_read(){
    ifstream data_in;
    string a,b,c;
    double d;
    data_in.open("data.txt",ios::in);
    while(data_in.good()){
        data_in>>a>>b>>c>>d;
        member temp(a,b,c,d);
        data_tree[a] = temp;
    }
    data_in.close();
    return;
}

 void data_write(){
    ofstream data_out;
    string a,b,c;
    double d;
    data_out.open("data.txt",ios::out);
    for(itor_map now = data_tree.begin();now != data_tree.end();now++){
        a = now->second.show_id();
        b = now->second.show_password();
        c = now->second.show_name();
        d = now->second.show_money();
        data_out<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    }
    data_out.close();
    return;
}

//////////////////////////////////////////////////////////////////////////////