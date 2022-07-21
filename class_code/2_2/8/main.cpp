#include"sort.hpp"

std::vector<my_sort::stu> students;
int n;

void input(){
    int a,b,c,d;
    std::string e;
    std::cin>>e>>a>>b>>c>>d;
    my_sort::stu temp(e,a,b,c,d);
    students.push_back(temp);
}

int main(){
    scanf("%d",&n);
    while(n--){
        input();
    }
    my_sort::sort(students);
    printf("result:\n");
    int i = students.size() - 1,flag = 1;
    for(;i >= 0;i--){
        students[i].print();
        if(flag++ == 5)
            break;
    }
    return 0;
}