#include<stdio.h>
char name[100];
int map[101][101],n,m,ans,used[101][101];
void dfs(int x,int y,int num){
    int now=map[x][y];
    ans>?=num;
    if(map[x-1][y]<now && x>1)
       dfs(x-1,y,num+1);
    if(map[x+1][y]<now && x<n)
        dfs(x+1,y,num+1);
    if(map[x][y-1]<now && y>1)
        dfs(x,y-1,num+1);
    if(map[x][y+1]<now && y<m)
        dfs(x,y+1,num+1);
}
main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%s %d %d",name,&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                used[i][j]=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                scanf("%d",&map[i][j]);
        for(i=1,ans=0;i<=n;i++)
            for(j=1;j<=m;j++)
                dfs(i,j,1);
        printf("%s: %d\n",name,ans);
    }
}
