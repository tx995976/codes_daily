#include<iostream>

using namespace std;
                       
int exam_index[100010],ans[100010];
int n,m,all,mult_ans,id=1;
double everge,temp;

inline int search(int k){
    int temp2 = 214000000;
    for(int i = k;k <= n;k++){
        temp=min(temp2,exam_index[i]);
    }
    return temp;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>exam_index[i];
        all+=exam_index[i];
    }
    for(int k = 1;k <= n-2;k++){
        all-=exam_index[k];
        int temp1 = all-search(k);
        temp = (double)temp1/(double)(n-1-k);
        if(temp > everge){
            ans[id++] = k;
            everge = temp;
            mult_ans = 1;
        }
        else if(temp == everge){
            mult_ans++;
            ans[id++]=k;
        }
        else    
            continue;
    }
    for(int j = id-mult_ans;j <= id-1;j++)
        cout<<ans[j]<<" ";
    cout<<endl;
    return 0;
}
