#include<stdio.h>
int map[101][101],dp[101][101];
int maxsum(int n,int s[]){
    int sum1,sum2,i,max=-2147483646,min=2147483647;
    for(i=sum1=sum2=0;i<n;i++){
        sum1+=s[i];
        sum2+=s[i];
        sum1>?=0;
        sum2<?=0;
        max>?=sum1;
        min<?=sum2;
    }
    for(i=sum1=0;i<n;i++)
        sum1+=s[i];
    max>?=(sum1-min);
    return max;
}
main(){
    int n,i,j,k,max,sum,tmp[101],t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        max=-2147483646;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%d",&map[i][j]),dp[i][j]=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                dp[i][j]=dp[i-1][j]+map[i][j];
        for(i=1;i<=n;i++)
            for(j=i;j<=n;j++){
                for(k=1;k<=n;k++)
                    tmp[k-1]=dp[j][k]-dp[i-1][k];
                max>?=maxsum(n,tmp);
                for(k=1;k<=n;k++)
                    tmp[k-1]=dp[n][k]-tmp[k-1];
                max>?=maxsum(n,tmp);
            }
        printf("%d\n",max);
    }
}