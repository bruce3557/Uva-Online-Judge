#include <stdio.h>
#include <string.h>

int dp[1010][3005],weight[1010],load[1010];

int main() {

	int n,max,maxweight;
	int i,j,k;
	
	while(scanf("%d",&n) && n) {
		memset(dp,0,sizeof(dp));
		maxweight = 0;
		for(i=1;i<=n;i++) {
			scanf("%d%d",weight+i,load+i);
			dp[i][load[i]] = 1;
			if(maxweight < load[i])
				maxweight = load[i];
		}
		
		for(i=1;i<=n;i++)
			for(j=0;j<=maxweight;j++) {
				if(dp[i-1][j]) {
					if(j-weight[i] >= 0) {
						if(load[i] < j-weight[i])
							k = load[i];
						else
							k = j-weight[i];
						if(dp[i][k] < dp[i-1][j]+1)
							dp[i][k] = dp[i-1][j]+1;
					}
					if(dp[i][j] < dp[i-1][j])
						dp[i][j] = dp[i-1][j];
				}
			}
		
		max = 1;
		for(i=0;i<=maxweight;i++)
			if(max < dp[n][i])
				max = dp[n][i];
		
		printf("%d\n",max);
	}

	return 0;
}
