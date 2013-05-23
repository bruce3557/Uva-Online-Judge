#include<stdio.h>
int s[100],dp[100][100];
main(){
    int i,j,n,len,k,l,min,tmp;
    while(scanf("%d",&len) && len){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&s[i]);
        s[0] = 0,s[++n] = len;
        for(l=1;l<=n;l++)
            for(i=0;i+l<=n;i++){
                j=i+l+1,min=99999999;
                for(k=i+1;k<j;k++)
                	if(min > (tmp = dp[i][k]+dp[k][j]+s[j]-s[i]))
	                    min = tmp;
                dp[i][j]=min;
            }
        printf("The minimum cutting is %d.\n",dp[0][n]);
    }
}
