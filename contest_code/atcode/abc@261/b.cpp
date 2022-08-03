#include<cstdio>
#include<algorithm>
#include<deque>
#include<string>
#include<vector>

char table[1010][1010];

int main(){
    int i;
    scanf("%d", &i);
    for(int j = 1; j <= i; j++)
        for(int k = 1; k <= i; k++)
            scanf(" %c", &table[j][k]);

    bool flag = 1;        
    for(int j = 1; j <= i; j++)
        for(int k = j+1; k <= i; k++){
            switch(table[j][k]){
                case 'D' :
                    if(table[k][j] != 'D') 
                        flag = 0;
                    break;        
                case 'W' :
                    if(table[k][j] != 'L')
                        flag = 0;
                    break;
                
                case 'L' :
                    if(table[k][j] != 'W')
                        flag = 0;
                    break;
            }
            if(flag == 0)
                break;
        }
    printf("%s\n", flag ? "correct" : "incorrect");
    return 0;
}