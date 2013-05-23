#include <stdio.h>

long long dp[1000020];

int main() {
	
	long long ans,c=0,n;
	
	while(scanf("%lld",&n) && n) {
		printf("Case %lld: ",++c);
		if(dp[n]) {
			printf("%lld\n",dp[n]);
			continue;
		}
		n -= 3;
		ans = (n+1)*(n+2)/2;
		if(n % 3 == 0)
			ans -= 1+n/2*3;
		else
			ans -= (n/2+1)*3;
		ans /= 6;
		dp[n+3] = ans;
		printf("%lld\n",ans);
	}
	
	return 0;
}
