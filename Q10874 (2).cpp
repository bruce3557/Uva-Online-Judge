#include<stdio.h>
int min(int a,int b){
    return (a<b)?(a):(b);
}
int abs(int x){
    return (x>0)?(x):(-x);
}
int dp[20001],l[20001],r[20001],n;
main(){
    int i,j;
    while(scanf("%d",&n) && n){
        for(i=0;i<n;i++)
            dp[i]=0;
        for(i=0;i<n;i++)
            scanf("%d %d",&l[i],&r[i]);
        dp[0]=r[i]-1;
        for(i=1;i<n;i++)
            dp[i]=dp[i-1]+min(abs(r[i-1]-l[i])-1,abs(l[i-1]-r[i])-1);
        printf("%d\n",dp[n-1]);
    }
}
