#include <stdio.h>

unsigned long long dp[100][100];

unsigned long long go(int n, int back) {
	if(n <= 1)	return 1;
	
	if(dp[n][back])
		return dp[n][back];
	
	unsigned long long sum = 0;	
	for(int i=1;i<=back;i++)
		sum += go(n-i,back);
		
	return dp[n][back] = sum+1;
}

int main() {
	
	int n,m,c=0;
	
	while(scanf("%d%d",&n,&m)  && n<=60)
		printf("Case %d: %llu\n",++c,go(n,m));

	return 0;
}
