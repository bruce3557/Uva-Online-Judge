#include <stdio.h>
#include <string.h>

long long dp[50][1000],n;

long long go(int i,int j) {
	if(dp[i][j])
		return dp[i][j];
		
	if(i >= j) {
		long long max1 = 0, max2 = 0, tmp;
		
		if(i < n) {
			for(int k=i+1;k<=n;k++)
				if(max1 < (tmp = go(k,1)+go(k,j)))
					max1 = tmp;
		}
		if(j > 0) {		
			for(int k=1;k<j;k++)
				if(max2 < (tmp = go(i,k)+go(n,k)))
					max2 = tmp;
		}
		
		return dp[i][j] = max1+max2;
	} else {
		long long max = 0,tmp;
		
		for(int k=i;k<j;k++)
			if(max < (tmp =go(i,k)+go(k+1,j)))
				max = tmp;
				
		return dp[i][j] = max;
	}
}

int main() {
	
	long long m;
	
	while(scanf("%lld%lld",&n,&m) != EOF) {
		memset(dp,0,sizeof(dp));
		dp[n][1] = m;
		printf("%lld\n",go(1,n));
	}
	
	return 0;
}
