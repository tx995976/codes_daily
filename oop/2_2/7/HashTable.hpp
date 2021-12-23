#include<iostream>
#include<algorithm>
#include<cstdio>

namespace my_hashtable{
    const int MaxSize_Table = 5e5;
    const int MaxSize_word = 50;
    const int MaxSize_Strings = 10;
    const int MinSize_Strings = 3;
    using hash_str = char[MaxSize_Strings];

    //存储文件所有词语hash
    struct FileEntry{
        int words;
        FileEntry *next;
    };


    //存储拥有词文件
    struct WordEntry{ 
        int FileNo;
        WordEntry *next;
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
            HashEntry *table[MaxSize_Table];

        public:
            ~HashTable(){}
            HashTable();

            int Insert_pos(hash_str input);
            int Insert_table(hash_str input,int FileNo);
            int Set_pos (int FileNo,int pos);
            double compare(int File1,int File2);

            int InitTable_Words(hash_str strs[]);

    };

    int Hash(char *str){
        unsigned hash = 0;
        while(*str != '0'){
            hash = (hash << 5) + (*str - 'a');
        }
        return hash % MaxSize_Table;
    }

    int HashTable::Insert_pos(hash_str input){
        return Hash(input);
    }
    
    int HashTable::Insert_table(hash_str input,int FileNo){


    }




 
}