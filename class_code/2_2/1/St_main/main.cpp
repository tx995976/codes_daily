#include <iomanip>
#include <iostream>
#include<algorithm>
#include"Sqlist.hpp"
#include"Student.hpp"


SqList<Student> St;

using namespace std;

int print_St(int i = 0){
    std::cout<<"序号"<<"   "<<"学号";
    std::cout<<"              "<<"姓名";
    std::cout<<"      "<<"绩点"<<std::endl;
    Student temp;
    while(St.Get(i,temp) != -1){
        std::cout<<i++<<".     "<<temp;
    }
    return 0;
}

int input_St(){
    int i;
    std::string id,name;
    double GMp;
    std::cout<<"数据(id,name,GP):"<<std::endl;
    std::cin>>id>>name>>GMp;
    Student temp(id,name,GMp);
    std::cout<<"位置:"<<std::endl;
    std::cin>>i;
    St.Insert(i,temp);
    return 0;
}

int search_St(){
    int i;
    Student temp_st;
    std::cout<<"输入序号继续"<<std::endl
             <<"1.按序号"<<std::endl
             <<"2.按学号"<<std::endl;
    std::cin>>i;
    switch(i){
        case 1:{
            std::cout<<"输入:"<<std::endl;
            std::cin>>i;
            if(St.Get(i,temp_st) == -1){
                std::cout<<"未找到"<<std::endl;
                return -1;
            }
            break;
        }
        case 2:{
            i = 0;
            std::cout<<"输入:"<<std::endl;
            std::string temp_str;
            std::cin>>temp_str;
            while(St.Get(i++,temp_st) != -1){
                if(temp_st.id == temp_str)
                    break;
            }
            if(i == St.GetLength()+1){
                std::cout<<"未找到"<<std::endl;
                return -1;
            }
            break;
        }
        default:
            std::cout<<"无效输入"<<std::endl;
            return -1;
    }
    std::cout<<"找到信息:"<<std::endl
             <<temp_st;
    return 0;
}

int Delete_St(){ 
    Student temp;
    std::cout<<"输入:"<<std::endl;
    int i;
    std::cin>>i;
    if(St.Delete(i,temp) == -1)
        return -1;
    return 0;
} 

int set_St(){
    int i;
    std::cout<<"输入位置:"<<std::endl;
    std::cin>>i;
    std::string id,name;
    double GMp;
    std::cout<<"数据(id,name,GP):"<<std::endl;
    std::cin>>id>>name>>GMp;
    Student temp(id,name,GMp);
    if(St.Set(i,temp) == -1)
        return -1;
    return 0;
}

int report_St(){
    std::cout<<"共有数据: "<<St.GetLength()<<"条"<<std::endl;
    return 0;
}

int sort_St(){
    cout<<"1.按绩点"<<endl
        <<"2.按学号"<<endl
        <<"选择方式:";
    int i;
    cin>>i;
    switch(i){
        case 1:
            sort(St.data,St.data+St.GetLength(),sort_GP);
            break;
        case 2:
            sort(St.data,St.data+St.GetLength(),sort_id);
            break;
    }
    return 0;
}


int clear_St(){
    St.clear();
    return 0;
}

//////////////////////////////////////////////////////
void menu(){
    using namespace std;
    int i;
    while(1){
        cout<<"1.显示"<<endl
            <<"2.录入"<<endl
            <<"3.查找"<<endl
            <<"4.删除"<<endl
            <<"5.更新"<<endl
            <<"6.统计"<<endl
            <<"7.排序"<<endl
            <<"8.清空"<<endl
            <<"0.退出"<<endl
            <<"input"<<endl;
            cin>>i;
            switch (i) {
                case 0:
                    return;
                case 1:
                    print_St();
                    break;
                case 2:
                    input_St();
                    break;
                case 3:
                    search_St();
                    break;
                case 4:
                    Delete_St();
                    break;
                case 5:
                    set_St();
                    break;
                case 6:
                    report_St();
                    break;
                case 7:
                    sort_St();
                    break;
                case 8:
                    clear_St();
                    break;
            default:
                cout<<"invaild_input,try again:"<<endl;
            }
    }

}

int main(){
    system("chcp 65001");
    menu();
    return 0;
}
