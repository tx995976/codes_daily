#include<iostream>
#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>


using ll = long long;
const int max_n = 300;

ll dx[max_n],dy[max_n];
bool flag[max_n][max_n];
int n,k,cnt,ans=0;
std::vector<int> p_list;

bool judge(int p1,int p2,int p3){
    ll k1 = (dy[p2] - dy[p1]) * (dx[p3] - dx[p1]);
    ll k2 = (dx[p2] - dx[p1]) * (dy[p3] - dy[p1]);
    return (k1 == k2);
}

int main(){
    scanf(" %d %d",&n,&k);
    for(int i = 0;i < n;i++)
        scanf(" %lld %lld",&dx[i],&dy[i]);
    
    if(k == 1){
        printf("Infinity\n");
        return 0;
    }
    for(int i = 0;i < n;i++)
        for(int j = i+1;j < n;j++)
            flag[i][j] = 1;

    for(int i = 0;i < n;i++)
        for(int j = i+1;j < n;j++){
            if(flag[i][j]){
                cnt = 2;
                p_list.clear();
                p_list.push_back(i);
                p_list.push_back(j);
                for(int di = j+1;di < n;di++){
                    if(judge(i,j,di)){
                        cnt++;
                        p_list.push_back(di);
                    }
                }
                for(int di = 0;di < cnt;di++)
                    for(int dj = di+1;dj < cnt;dj++)
                        flag[p_list[di]][p_list[dj]] = 0;
                if(cnt >= k)
                    ans++;
            }
        }
    printf("%d\n",ans);
    return 0;
}