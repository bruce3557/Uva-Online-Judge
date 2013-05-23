#include<stdio.h>
char map[5][5],used[5][5];
int max,n;
bool check(int x,int y){
    int i;
    for(i=1;x+i<n;i++)
        if(map[i+x][y]=='X')
            break;
        else if(used[x+i][y])
            return 0;
    for(i=1;x-i>=0;i++)
        if(map[x-i][y]=='X')
            break;
        else if(used[x-i][y])
            return 0;
    for(i=1;y+i<n;i++)
        if(map[x][y+i]=='X')
            break;
        else if(used[x][y+i])
            return 0;
    for(i=1;y-i>=0;i++)
        if(map[x][y-i]=='X')
            break;
        else if(used[x][y-i])
            return 0;
    return 1;
}
void go(int x,int y,int sum){
    int i,j;
    max>?=sum;
    used[x][y]=1;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(check(i,j) && used[i][j]==0 && map[i][j]!='X')
                go(i,j,sum+1);
    used[x][y]=0;
}
main(){
    int i,j;
    while(scanf("%d",&n) && n){
        for(i=0;i<n;i++)
            scanf("%s",map[i]);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                used[i][j]=0;
        for(i=max=0;i<n;i++)
            for(j=0;j<n;j++)
                if(map[i][j]!='X')
                    go(i,j,1);
        printf("%d\n",max);
    }
}
