#include<stdio.h>
int dp[501][501];
int go(int n,int k){
    int i,min=2147483647;
    if(dp[n][k])    return dp[n][k];
    if(n<=1)        return 0;
    for(i=1;i<=n;i++)
         min<?=go(i-1,k)+go(n-i,i+k)+(i+k)*n;
    return dp[n][k]=min;
}
main(){
    int t,c=0,n,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        printf("Case %d: %d\n",++c,go(n,k));
    }
}
