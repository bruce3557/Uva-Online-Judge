#include <stdio.h>
#define MAX 100000

int dp[MAX+10];

int main() {

	int i,a,b;
	
	for(i=1;i*i<=MAX;i++)
		dp[i*i] = 1;
	
	for(i=1;i<=MAX;i++)
		dp[i] += dp[i-1];
	
	while(scanf("%d%d",&a,&b) && a+b) {
		printf("%d\n",dp[b]-dp[a-1]);
	}

	return 0;
}
