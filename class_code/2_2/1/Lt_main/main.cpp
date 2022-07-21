#include <iostream>
#include <iomanip>
#include<algorithm>
#include"Linklist.hpp"
#include"Student.hpp"


LinkList<Student> Lt;

using namespace std;
///////////////////////////////////////////////////////////////////////////
int print_Lt(int i = 1){
    std::cout<<"序号"<<"   "<<"学号";
    std::cout<<"              "<<"姓名";
    std::cout<<"      "<<"绩点"<<std::endl;
    Student temp;
    while(Lt.Get(i,temp) != -1){
        std::cout<<i++<<".     "<<temp;
    }
    return 0;
}

int input_Lt(){
    int i;
    std::string id,name;
    double GMp;
    std::cout<<"数据(id,name,GP):"<<std::endl;
    std::cin>>id>>name>>GMp;
    Student temp(id,name,GMp);
    std::cout<<"位置:"<<std::endl;
    std::cin>>i;
    Lt.Insert(i, temp);
    return 0;
}

int search_Lt(){
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
            if(Lt.Get(i,temp_st) == -1){
                std::cout<<"未找到"<<std::endl;
                return -1;
            }
            break;
        }
        case 2:{
            i--;
            std::cout<<"输入:"<<std::endl;
            std::string temp_str;
            std::cin>>temp_str;
            while(Lt.Get(i++,temp_st) != -1){
                if(temp_st.id == temp_str)
                    break;
            }
            if(i == Lt.GetLength()+2){
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

int Delete_Lt(){ 
    Student temp;
    std::cout<<"输入:"<<std::endl;
    int i;
    std::cin>>i;
    if(Lt.Delete(i,temp) == -1)
        return -1;
    return 0;
} 

int set_Lt(){
    int i;
    std::cout<<"输入位置:"<<std::endl;
    std::cin>>i;
    std::string id,name;
    double GMp;
    std::cout<<"数据(id,name,GP):"<<std::endl;
    std::cin>>id>>name>>GMp;
    Student temp(id,name,GMp);
    if(Lt.Set(i,temp) == -1)
        return -1;
    return 0;
}

int report_Lt(){
    std::cout<<"共有数据: "<<Lt.GetLength()<<"条"<<std::endl;
    return 0;

}

int sort_Lt(int begin = 0){
    int i;
    std::cout<<"1.按绩点"<<endl
        <<"2.按学号"<<endl
        <<"选择方式:";
    std::cin>>i;
    int size = Lt.GetLength();
    Student temp[size];
    switch(i){
        case 1:{
            while(Lt.GetLength() != 0)
                Lt.Delete(1,temp[begin++]);
            sort(temp,temp+size,sort_GP);
            for(int i = 1;i <= size;i++)
                Lt.Insert(i,temp[i-1]);
            break;
        }
        case 2:{
            while(Lt.GetLength() != 0)
                Lt.Delete(1,temp[begin++]);
            sort(temp,temp+size,sort_id);
            for(int i = 1;i <= size;i++)
                Lt.Insert(i,temp[i-1]);
            break;
        }
        default:
            std::cout<<"无效输入"<<std::endl;
            return -1;
    }
    return 0;
}

int free_Lt(int i = 1){
    Student temp;
    while(Lt.GetLength() != 0){
        Lt.Delete(i,temp);
    }
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
                    print_Lt();
                    break;
                case 2:
                    input_Lt();
                    break;
                case 3:
                    search_Lt();
                    break;
                case 4:
                    Delete_Lt();
                    break;
                case 5:
                    set_Lt();
                    break;
                case 6:
                    report_Lt();
                    break;
                case 7:
                    sort_Lt();
                    break;
                case 8:
                    free_Lt();
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
