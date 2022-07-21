#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

const int max_n = 1e6+10;
int l1,l2,r1,r2;
bool nums_flag [11];
int num1[11],num2[11];
struct num{
    int z1,z2,m1,m2;
    num(int a,int b,int c,int d){z1 = a;z2 = c;m1 = b;m2 = d;}
    num(){}
}ans[max_n];

int gcd(int a,int b){
    return b ? gcd(b,a%b) : a;
}

bool cmp(const num &l,const num &r){
    return l.z2 * r.m2 < l.m2 *r.z2 || (l.z2 * r.m2 == l.m2 *r.z2 && l.z1 <r.z1);
}

bool contain_judge(int m,int n){
    *num1 = *num2 = 0;
    while(m){
        num1[++ *num1] = m%10;
        m /= 10;
    }
    while(n){
        num2[++ *num2] = n%10;
        n /= 10;
    }
    for(int a = *num1,b = *num2;a && b; a--){
        if(num1[a] == num2[b])
            if(!(--b))
                return 1;
    }
    return 0;
}

bool value_check(int fz ,int fz_c,int fm,int fm_c){
    memset(num1,0,sizeof(num1));
    memset(num2,0,sizeof(num2));
    while(fz)
        ++num1[fz%10],fz /= 10;
    while(fz_c)
        --num1[fz_c%10],fz_c /= 10;
    while(fm)
        ++num2[fm%10],fm /= 10;
    while(fm_c)
        --num2[fm_c%10],fm_c /= 10;
    for(int i = 0;i < 10;i++){
        if(num1[i] != num2[i])
            return 0;
    }
    return 1;
}

bool wro_check(int a,int b){
    memset(nums_flag,0,sizeof(nums_flag));
    while(a){
        nums_flag[a%10] = 1;
        a /= 10;
    }
    while(b){
        if(nums_flag[b%10])
            return 0;
        b /= 10;
    }
    return 1;
}

void solve(){
int ans_num = 0;
    for(int fz = l1; fz <= r1;fz++)
        for(int fm = l2; fm <= r2;fm++){
            int fs_gcd = gcd(fz,fm);
            if(fs_gcd == 1){
                if(wro_check(fz,fm))
                    ans[ans_num++] = num(fz,fm,fz,fm);
                continue;
            }
            int fz_c = fz/fs_gcd , fm_c = fm/fs_gcd;
            if(wro_check(fz_c,fm_c) && contain_judge(fz,fz_c) && contain_judge(fm,fm_c) && value_check(fz,fz_c,fm,fm_c))
                ans[ans_num++] = num(fz,fm,fz_c,fm_c);
        }
    std::sort(ans,ans+ans_num,cmp);
    printf("%d\n",ans_num);
    for(int i = 0;i < ans_num;i++)
         printf("%d/%d=%d/%d\n",ans[i].z1,ans[i].m1,ans[i].z2,ans[i].m2);
    return;
}

int main(){
    scanf("%d %d",&l1,&r1);
    scanf("%d %d",&l2,&r2);
    solve();
    return 0;
}