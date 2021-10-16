#include <iomanip>
#include <iostream>
#include"Sqlist.hpp"
#include"Student.hpp"


SqList<Student> Lt;

using namespace std;

int print_St(int i = 1){
   
    return 0;
}

int input_St(){
   
}

int search_St(){

  

}

int Delete_St(){ 

} 

int set_St(){
    

}

int report_St(){}

int sort_St(){}

int clear_St(){}

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
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    break;
                case 8:
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
