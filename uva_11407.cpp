#include <stdio.h>
#define MAX 10000

int s[110],dp[MAX+10];

int main() {

	int i,j,t,n;
	
	for(i=1;i<=MAX;i++)
		dp[i] = MAX;
	
	for(i=1;i<=100;i++) {
		s[i] = i*i;
		dp[s[i]] = 1;
	}
	
	dp[0] = 0;
	
	for(i=1;i<=100;i++)
		for(j=s[i];s[i]+j<=MAX;j++)
			if(dp[s[i]+j] > dp[j]+1)
				dp[s[i]+j] = dp[j]+1;
	
	scanf("%d",&t);
	
	while(t--) {
		scanf("%d",&n);
		printf("%d\n",dp[n]);
	}

	return 0;
}
