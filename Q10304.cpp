#include<stdio.h>
int dp[255][255],n,s[255],p[255][255];
main(){
    int i,j,k,best;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++){
            scanf("%d",&s[i]);
            s[i]+=s[i-1];
            for(j=1;j<i;j++)
                dp[j][i]=1e9;
            p[i][i]=i;
        }
        for(i=0;i<n;i++)
            for(j=1;i+j<=n;j++)
                for(k=p[j][i+j-1];k<=p[j+1][i+j];k++){
                    best=dp[j][k-1]+dp[k+1][i+j]+s[i+j]-s[k]+s[k-1]-s[j-1];
                    if(best<dp[j][i+j]){
                        dp[j][i+j]=best;
                        p[j][i+j]=k;
                    }
                }
        printf("%d\n",dp[1][n]);
    }
}
