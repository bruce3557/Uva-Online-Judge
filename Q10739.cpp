#include <stdio.h>
#include <string.h>

int dp[1010][1010],n;
char s[1010];

int Min(int a,int b) {
	return a<b?a:b;
}

int go(int i,int j) {
	if(i >= j)	return 0;
	if(dp[i][j] != 999999999)	return dp[i][j];
	if(s[i] == s[j])
		return go(i+1,j-1);
	else {
		int a,b,c,min;
		a = go(i+1,j-1)+1;
		b = go(i+1,j)+1;
		c = go(i,j-1)+1;
		min = Min(Min(a,b),c);
		return dp[i][j] = min;
	}
}

int main() {
	int t,i,j,c=0;
	
	scanf("%d%*c",&t);
	while(t--) {
		gets(s);
		n = strlen(s);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				dp[i][j] = 999999999;
		printf("Case %d: %d\n",++c,go(0,n-1));
	}
	
	return 0;
}
