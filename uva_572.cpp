#include<stdio.h>
#include<string.h>

char oil[200][200],tmp;
int used[200][200],n,m;

void dfs(int x,int y){
    if(!used[x-1][y-1] && oil[x-1][y-1]=='@'){
        used[x-1][y-1]=1;
        dfs(x-1,y-1);
    }
    if(!used[x][y-1] && oil[x][y-1]=='@'){
        used[x][y-1]=1;
        dfs(x,y-1);
    }
    if(!used[x+1][y-1] && oil[x+1][y-1]=='@'){
        used[x+1][y-1]=1;
        dfs(x+1,y-1);
    }
    if(!used[x-1][y] && oil[x-1][y]=='@'){
        used[x-1][y]=1;
        dfs(x-1,y);
    }
    if(!used[x+1][y] && oil[x+1][y]=='@'){
        used[x+1][y]=1;
        dfs(x+1,y);
    }
    if(!used[x-1][y+1] && oil[x-1][y+1]=='@'){
        used[x-1][y+1]=1;
        dfs(x-1,y+1);
    }
    if(!used[x][y+1] && oil[x][y+1]=='@'){
        used[x][y+1]=1;
        dfs(x,y+1);
    }
    if(!used[x+1][y+1] && oil[x+1][y+1]=='@'){
        used[x+1][y+1]=1;
        dfs(x+1,y+1);
    }
    return;
}

main(){
    int i,j,count;
    while(scanf("%d %d",&m,&n) && m && n){
        for(i=1;i<=m;i++)
            for(j=1;j<=n+1;j++){
                scanf("%c",&oil[i][j]);
                used[i][j]=0;
            }
        count=0;
        for(i=1;i<=m;i++)
            for(j=1;j<=n+1;j++)
                if(!used[i][j] && oil[i][j]=='@'){
                    used[i][j]=1;
                    dfs(i,j);
                    count++;
                }
        printf("%d\n",count);
    }
}
