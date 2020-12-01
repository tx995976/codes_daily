#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3;
char mp[maxn][maxn];
int n, T;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                scanf"%c", &mp[i][j]);
            }
        }
        int flag = 1;
        int ans = 0;
        if(n % 2 == 1){
            if(mp[(n-1)/2+1][(n-1)/2+1] != 'O'){
                flag = 0;
            }
        }
        if(flag == 1){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if(i == n-i+1 && j == n-j+1)
                        continue;
                    if(mp[i][j] == 'M'){
                        if(mp[n-i+1][n-j+1] == 'M'){
                            ans++;
                        }
                        else if(mp[n-i+1][n-j+1] == 'W'){
                            continue;
                        }
                        else if(mp[n-i+1][n-j+1] == 'O'){
                            flag = 0;
                            break;
                        }
                    }
                    else if(mp[i][j] == 'W'){
                        if(mp[n-i+1][n-j+1] == 'W'){
                            ans++;
                        }
                        else if(mp[n-i+1][n-j+1] == 'M'){
                            continue;
                        }
                        else if(mp[n-i+1][n-j+1] == 'O'){
                            flag = 0;
                            break;
                        }
                    }
                    else if(mp[i][j] == 'O'){
                        if(mp[n-i+1][n-j+1] == 'O'){
                            continue;
                        }
                        else{
                            flag = 0;
                            break;
                        }
                    }
                }
                if(flag == 0)
                    break;
            }
        }
        if(flag)
            printf("%d\n", ans/2);
        else
            printf("%d\n", -1);
    }
    //fclose(in);
    //fclose(out);
    return 0;
}
