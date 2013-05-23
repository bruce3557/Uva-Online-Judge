#include <stdio.h>

int n,dp[2010],s[110],ans[110],ansm;

int main() {
    int i,j,k,l,m,max,f;

    while(scanf("%d",&n) && n) {
        scanf("%d",&m);
        max = -1;
        while(m--) {
            scanf("%d",&k);
            for(i=0;i<k;i++)
                scanf("%d",s+i);
            for(i=0;i<=2000;i++)
                dp[i] = 99999;
            dp[0] = 0;
            for(i=0;i<k;i++)
                for(j=s[i];j<=2000;j++)
                    if(dp[j-s[i]]+1 < dp[j])
                        dp[j] = dp[j-s[i]]+1;
            for(i=1;i<=2000 && dp[i] <= n;i++);
            if(i-1 > max) {
                max = i-1;
                ansm = k;
                for(j=0;j<k;j++)
                    ans[j] = s[j];
            } else if(i-1 == max) {
                if(k < ansm) {
                    ansm = k;
                    for(j=0;j<k;j++)
                        ans[j] = s[j];
                } else if(k == ansm) {
                    f = 0;
                    for(j=k-1;j>=0;j--) {
                        if(s[j] == ans[j])
                            continue;
                        else if(s[j] < ans[j]) {
                            f = 1;
                            break;
                        }
                    }
                    if(f == 1) {
                        for(j=k-1;j>=0;j--)
                            ans[j] = s[j];
                    }
                }
            }
        }
        printf("max coverage =%4d :",max);
        for(i=0;i<ansm;i++)
            printf("%3d",ans[i]);
        puts("");
    }

    return 0;
}
