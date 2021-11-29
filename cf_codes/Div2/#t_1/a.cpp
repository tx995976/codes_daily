#include<iostream>
#include<algorithm>
#include<cstdio>

const int max_n = 1e2+10;
int t,i = 0;

struct version{
    int ver[max_n],nums;
};
version ver_num[max_n];

bool cmp(const version &l,const version &r){
    int l_n = l.nums,r_n = r.nums;
    for(int i_l = 1,i_r = 1;i_l <= l_n && i_r <=r_n;i_l++,i_r++){
        if(l.ver[i_l] != r.ver[i_r])
            return l.ver[i_l] < r.ver[i_r];
    }
    return l.nums < r.nums ;
}

int main(){
    scanf("%d",&t);
    while(t--){
        char t_char = '.';
        int j = 1;
        i++;
        while(t_char == '.'){
            scanf("%d%c",&ver_num[i].ver[j++],&t_char);
            ver_num[i].nums++;
        }
    }
    std::sort(ver_num+1,ver_num+i+1,cmp);
    for(int i = 1;i <= ::i;i++){
        for(int j = 1;j < ver_num[i].nums;j++)
            printf("%d.",ver_num[i].ver[j]);
        printf("%d\n",ver_num[i].ver[ver_num[i].nums]);
    }
    return 0;
}