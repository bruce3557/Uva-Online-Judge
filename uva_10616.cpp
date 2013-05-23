#include <stdio.h>
#include <string.h>

int n,m;
int s[210];
long long dp[210][20][20];

int main() {
	int cases=0;
	
	while( scanf("%d %d",&n, &m) && n+m ) {
		for(int i=0;i<n;++i)
			scanf("%d",s+i);
		
		int q=0;
		printf("SET %d:\n",++cases);
		while(m--) {
			int d, r;
			scanf("%d %d",&d,&r);
			memset(dp, 0, sizeof(dp));
			int x = s[0]%d;
			while(x < 0)	x += d;
			dp[0][0][0] = 1;
			dp[0][1][x] += 1;
			for(int i=1;i<n;++i)
				for(int j=0;j<=r;++j)
					for(int k=0;k<d;++k) {
						int next = (k+s[i])%d;
						while(next < 0)	next += d;
						dp[i][j+1][next] += dp[i-1][j][k];
						dp[i][j][k] += dp[i-1][j][k];
					}
			
			printf("QUERY %d: %lld\n",++q,dp[n-1][r][0]);
		}
	}

	return 0;
}
