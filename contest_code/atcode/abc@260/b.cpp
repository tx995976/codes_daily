#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

const int max_n = 1010;
int N,X,Y,Z;

struct scope{
    int id,math,english;
    bool operator < (const scope& other) const {
        if(math == other.math)
            return id > other.id;
        return math < other.math;
    }
};

bool cmp_eng(const scope& l, const scope& r) {
    if(l.english == r.english)
        return l.id > r.id;
    return l.english < r.english;
}

bool cmp_all(const scope& l, const scope& r) {
    int a_l = l.english + l.math;
    int a_r = r.english + r.math;

    if(a_l == a_r)
        return l.id > r.id;
    return a_l < a_r;
}

scope examinee[max_n];
bool admitted[max_n];

int main(){
    scanf("%d %d %d %d",&N,&X,&Y,&Z);
    for(int i = 1 ; i <= N;i++){
        scanf(" %d",&examinee[i].math);
        examinee[i].id = i;
    }
    for(int i = 1 ; i <= N;i++)
        scanf(" %d",&examinee[i].english);
    int en_pos = N;

    if(X != 0){
        std::sort(examinee+1,examinee+en_pos+1);
        for(int i = 1 ; i <= X;i++)
            admitted[examinee[en_pos--].id] = true;
    }
    if(Y != 0){
        std::sort(examinee+1,examinee+en_pos+1,cmp_eng);
        for(int i = 1 ; i <= Y;i++)
            admitted[examinee[en_pos--].id] = true;
    }
    if(Z != 0){
        std::sort(examinee+1,examinee+en_pos+1,cmp_all);
        for(int i = 1 ; i <= Z;i++)
            admitted[examinee[en_pos--].id] = true;
    }
    for(int i = 1;i <= N;i++)
        if(admitted[i])
            printf("%d\n",i);
    return 0;
}