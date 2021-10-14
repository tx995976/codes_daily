#include <iomanip>
#include <iostream>
#include"Linklist.hpp"
#include"Student.hpp"


LinkList<Student> Lt;


int print_Lt(int i = 1){
    std::cout<<""<<std::setw(15)<<""<<std::setw(6)<<""<<std::setw(6)<<""<<std::endl;
    Student *temp;
    Lt.Get(1,*temp);
    while(temp != nullptr){
        std::cout<<i++<<".  "<<temp;
    }
    return 0;
}

int input_Lt(){
    int i;
    std::string id,name;
    double GMp;
    std::cin>>id>>name>>GMp;
    Student temp(id,name,GMp);
    std::cin>>i;
    Lt.Insert(i, temp);
    
}

int search_Lt(){

    std::string input;
    std::cin>>input;


}

int Delete_Lt(){ 
    int i;
    Student temp;
    std::cin>>i;
    Lt.Delete(i,temp);
    return 0;
} 

int set_Lt(){
    

}









//////////////////////////////////////////////////////
void menu(){
    using namespace std;
    int i;
    cout<<"1"<<endl
        <<"2"<<endl
        <<"3"<<endl
        <<"4"<<endl
        <<"5"<<endl
        <<"6"<<endl
        <<"7"<<endl
        <<"8"<<endl
        <<"input"<<endl;
        cin>>i;
        switch (i) {
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

int main(){

    return 0;
}
