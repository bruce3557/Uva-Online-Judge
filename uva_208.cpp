#include<stdio.h>
int ans,ed;
char map[101][101],used[101],path[101];
void dfs(int num,int now){
    int i;
    if(now==ed){
        printf("1");
        for(i=2;i<=num;i++)
            printf(" %d",path[i]);
        puts("");
        ans++;
        return;
    }
    for(i=1;i<=21;i++)
        if(map[now][i]==1 && used[i]==0){
            used[i]=1;
            path[num+1]=i;
            dfs(i,num+1);
            used[i]=0;
        }
}
main(){
    int i,t=0,j;
    while(scanf("%d",&ed)!=EOF){
        ans=0;
        for(i=1;i<=21;i++,used[i]=0)
            for(j=1;j<=21;j++)
                map[i][j]=0;
        while(scanf("%d %d",&i,&j) && i+j)
            map[i][j]=map[j][i]=1;
        used[1]=path[1]=1;
        dfs(1,1);
        printf("CASE %d:\n",++t);
        printf("There are %d routes from the firestation to streetcorner %d.\n",ans,ed);
    }
}
