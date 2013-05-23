#include <stdio.h>

int dp[10010][10010];

int main() {

	int i,j,k,c=0,max;
	
	for(i=1;i<=26;i++)
		dp[1][i] = 1;
	for(i=2;i<=26;i++) {
		for(j=2;j<=26;j++)
			for(k=26*i;k>i;k--)
				if(dp[i-1][k-i] > 0)
					dp[i][k] += dp[i-1][k-i];
	}
	
	while(scanf("%d%d",&i,&j) && i+j)
		printf("Case %d: %d\n",++c,dp[i][j]);
	
	return 0;
}
