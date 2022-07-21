#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>

namespace my_hashtable{
    const int MaxSize_Table = 5e5;
    const int MaxSize_word = 50;
    const int MaxSize_Strings = 10;
    const int MinSize_Strings = 3;


    //using hash_str = char[MaxSize_Strings];
    //typedef char hash_str[MaxSize_Strings];

    
    
    struct hash_str{
        char str[MaxSize_Strings];
    };

    //存储文件所有词语hash
    struct FileEntry{
        int pos;
        FileEntry *next;
        FileEntry(){}
        FileEntry(int in){pos = in;next = nullptr;}
    };


    //存储拥有词文件
    struct WordEntry{ 
        int FileNo;
        WordEntry *next;
        WordEntry(){}
        WordEntry(int i){FileNo = i;next = nullptr;}
    };

    struct HashEntry{
        int FileNO;   //上次更新编号
        WordEntry *InvIndex; //拥有表
        hash_str str;
        //
        HashEntry *nextElem;
    };

    class HashTable{
        private:
            int FileSize;
            FileEntry *files[MaxSize_word];
            HashEntry *table;

        public:
            ~HashTable(){}
            HashTable();

            int Insert_pos(hash_str input);
            int Insert_table(hash_str input,int FileNo);
            int Set_pos (int FileNo,int pos);
            double compare(int File1,int File2);

            int InitTable_Words(std::vector<hash_str> &strs,int File);

    };

    int Hash(char str[]){
        unsigned hash = 0;
        while(*str != '\000'){
            hash = (hash << 5) + (*str - 'a');
            str++;
        }
        return hash % MaxSize_Table;
    }
    
    HashTable::HashTable(){
        FileSize = 0;
        table = new HashEntry[MaxSize_Table];
    }

    int HashTable::Insert_pos(hash_str input){
        return Hash(input.str);
    }
    

    //不解决冲突
    int HashTable::Insert_table(hash_str input,int FileNo){
        WordEntry *filelog;
        int pos = this->Insert_pos(input);
        if(table[pos].FileNO != FileNo){
            if(!table[pos].FileNO){
                //
                strcpy(table[pos].str.str,input.str);
            }
            table[pos].FileNO = FileNo;
            filelog = new WordEntry(FileNo);
            filelog->next = table[pos].InvIndex;
            table[pos].InvIndex = filelog;
            //
            Set_pos(FileNo,pos);
            return pos;
        }
        return -1;
    }

    int HashTable::Set_pos(int FileNo,int pos){
        if(files[FileNo] == nullptr){
            files[FileNo] = new FileEntry(pos);
            return 1;
        }

        auto it = files[FileNo];
        while(it->next != nullptr)
            it = it->next;
        it->next = new FileEntry(pos);
        return 0;
    }

    double HashTable::compare(int File1,int File2){
        double cnt = 0,all = 0;
        FileEntry *f1,*f2;
        f1 = files[File1];
        f2 = files[File2];
        //共有,一部分总体
        while(f1 != nullptr){
            auto it = table[f1->pos].InvIndex;
            while(it != nullptr){
                if(it->FileNo == File2){
                    cnt += 1;
                    break;
                }
                it = it->next;
            }
            all += 1;
            f1 = f1->next;
        }
        //剩余总体词汇
        while(f2 != nullptr){
            auto it = table[f2->pos].InvIndex;
            while(it != nullptr){
                if(it->FileNo == File1)
                    break;
                it = it->next;
            }
            if(it == nullptr)
                all += 1;
            f2 = f2->next;
        }
        return (cnt/all);
    }

    int HashTable::InitTable_Words(std::vector<hash_str> &strs,int File){
        if(files[File] != nullptr){
            return -1;
        }
        for(auto it : strs){
            Insert_table(it,File);
        }
        this->FileSize++;
        return 0;
    }

}