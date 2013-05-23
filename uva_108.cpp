#include<stdio.h>
int map[101][101],dp[101][101];
main(){
    int n,i,j,k,max=-2147483646,sum;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&map[i][j]);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            dp[i][j]=dp[i-1][j]+map[i][j];
    for(i=1;i<=n;i++)
        for(j=i;j<=n;j++)
            for(k=1,sum=0;k<=n;k++){
                sum+=dp[j][k]-dp[i-1][k];
                sum>?=0;
                max>?=sum;
            }
    printf("%d\n",max);
    scanf("  ");
}
