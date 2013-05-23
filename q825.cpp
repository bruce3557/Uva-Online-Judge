#include<stdio.h>
#include<string.h>
int map[101][101],dp[101][101];
main(){
    int t,i,j,n,m,a,b,cnt=0;
    char *ptr,line[1000];
    gets(line);
    sscanf(line,"%d",&t);
    while(t--){
        gets(line);
        gets(line);
        sscanf(line,"%d %d",&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                map[i][j]=dp[i][j]=0;
        for(a=1;a<=n;a++){
            gets(line);
            ptr=strtok(line," ");
            ptr=strtok(NULL," ");
            while(ptr!=NULL){
                sscanf(ptr,"%d",&b);
                map[a][b]=1;
                ptr=strtok(NULL," ");
            }
        }
        if(cnt) puts("");
        else    cnt=1;
        dp[1][1]=1,map[1][1]=1;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                if(map[i][j]==0)
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
        printf("%d\n",dp[n][m]);
    }
}
