#include"HashTable.hpp"


my_hashtable::HashTable word_table;
std::vector<my_hashtable::hash_str> comple_str;
std::vector<std::string> strs;

int num_file = 1;

void str_read(){
    std::string temp_str;
    my_hashtable::hash_str elem_temp;
    int elem_len = 0;
    bool full_flag = 0,overflow_flag=0;
    char in = ' ';
    fflush(stdin);
    in = getchar();
    while(in != '#'){
        temp_str.push_back(in);
        if(in >= 'a' && in <= 'z'){
            if(full_flag){
                overflow_flag = 1;
            }
            else{
                elem_temp.str[elem_len++] = in;
                if(elem_len == my_hashtable::MaxSize_Strings)
                    full_flag = 1; 
            }
        }
        else if(in >= 'A' && in <= 'Z'){
            if(full_flag){
                overflow_flag = 1;
            }
            else{
                in = (in-'A')+'a';
                elem_temp.str[elem_len++] = in;
                if(elem_len == my_hashtable::MaxSize_Strings)
                    full_flag = 1;
            }
        }
        else{
            if(!overflow_flag && elem_len >= my_hashtable::MinSize_Strings){
                my_hashtable::hash_str elem;
                strcpy(elem.str,elem_temp.str);
                comple_str.push_back(elem);
            }
            memset(elem_temp.str,0,sizeof(my_hashtable::hash_str));
            elem_len = 0,full_flag = 0,overflow_flag = 0;
        }

        in = getchar();
        if(in == '\n'){
            fflush(stdin);
            in = ' ';
        }
    }

    strs.push_back(temp_str);    
    
    return;
}

void new_file(){
    printf("input(end flag: #):\n");
    str_read();
    word_table.InitTable_Words(comple_str,num_file);
    comple_str.clear();
    printf("complete\nFile ID:%d\n",num_file++);
    return;
}


void compare_file(){
    int f1,f2;
    double result;
    printf("input: id(file1,file2):\n");
    scanf("%d %d",&f1,&f2);
    result = word_table.compare(f1,f2);
    printf("result:%.1f%\n",(double)result*100);
}


void menu(){
    while(1){
        printf("1.add files\n");
        printf("2.cal_compare\n");
        printf("0.exit\n");
        int i = 6;
        scanf("%d",&i);
        switch(i){
            case 1:
                new_file();
                break;
            case 2:
                compare_file();
                break;
            case 0:
                return;
            default:
                printf("invaild input\n");
                break;
        }
    }
}

int main(){
    menu();
    return 0;
}