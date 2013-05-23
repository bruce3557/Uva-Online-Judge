#include <stdio.h>
#include <string.h>

int min;
char map[30][30],tmp[30][30];

void change(char map[30][30],int x,int y) {
    if(map[x][y] == 0)  map[x][y] = 1;
    else                map[x][y] = 0;
    if(x-1 > 0) {
        if(map[x-1][y] == 0)  map[x-1][y] = 1;
        else                  map[x-1][y] = 0;
    }
    if(x+1 <= 10) {
        if(map[x+1][y] == 0)  map[x+1][y] = 1;
        else                  map[x+1][y] = 0;
    }
    if(y-1 > 0) {
        if(map[x][y-1] == 0)  map[x][y-1] = 1;
        else                  map[x][y-1] = 0;
    }
    if(y+1 <= 10) {
        if(map[x][y+1] == 0)  map[x][y+1] = 1;
        else                  map[x][y+1] = 0;
    }
}

void check(int sum) {
    int i,j,k;
    int press = 0;
    for(i=1;i<=10;i++)
        for(j=1;j<=10;j++)
            tmp[i][j] = map[i][j];
            
    for(i=2;i<=10;i++)
        for(j=1;j<=10;j++)
            if(tmp[i-1][j] == 1) {
                change(tmp,i,j);
                press++;
            }
    for(i=1;i<=10;i++) {
        for(j=1;j<=10;j++)
            if(tmp[i][j] == 1)
                break;
        if(j <= 10) break;
    }

    if(i <= 10)  return;
    
    if(min > press+sum)
        min = press+sum;
}

void go(int y,int sum) {
    if(y > 10) {
        check(sum);
        return;
    }
    //not press
    go(y+1,sum);
    //press
    change(map,1,y);
    go(y+1,sum+1);
    change(map,1,y);
}

int main() {
    int i,j;
    char name[500];
    
    while(scanf("%s",name) && strcmp(name,"end")) {
        min = 999;
        for(i=1;i<=10;i++)
            scanf("%s",map[i]+1);
        getchar();
        for(i=1;i<=10;i++)
            for(j=1;j<=10;j++) {
                if(map[i][j] == '#')
                    map[i][j] = 0;
                else
                    map[i][j] = 1;
            }
        go(1,0);
        
        if(min > 100)
            printf("%s -1\n",name);
        else
            printf("%s %d\n",name,min);        
    }
    
    return 0;    
}
