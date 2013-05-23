#include<algorithm>
struct node{
    int V,K,C,L;
    bool operator < (node t) const{
        return V>t.V;
    }
}s[1001];
int dp[1001][15];
main(){
    int i,j,mins,n;
    while(scanf("%d",&n) && n){
        memset(dp,-1,sizeof(dp));
        for(i=0;i<n;i++)
            scanf("%d %d %d %d",&s[i].V,&s[i].K,&s[i].C,&s[i].L);
        std::sort(s,s+n);
        dp[0][s[0].C]=s[0].K+s[0].C*s[0].L;
        for(i=1;i<n;i++){
            for(j=1;j<11;j++)
                if(dp[i-1][j]!=-1)
                    dp[i][j]=dp[i-1][j]+j*s[i].L;
            for(j=1;j<11;j++)
                if(dp[i-1][j]!=-1){
                    if(dp[i][s[i].C]!=-1)
                        dp[i][s[i].C]<?=dp[i-1][j]+s[i].K+s[i].C*s[i].L;
                    else
                        dp[i][s[i].C]=dp[i-1][j]+s[i].K+s[i].C*s[i].L;
                }
        }
        mins=999999999;
        for(i=0;i<11;i++)
            if(dp[n-1][i]!=-1)        
                mins<?=dp[n-1][i];
        printf("%d\n",mins);
    }
}
