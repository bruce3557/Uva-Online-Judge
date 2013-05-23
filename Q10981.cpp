#include <stdio.h>
#include <string.h>

char s[110],target;
int dp[110][110];

int go(int st,int ed) {
	if(dp[st][ed])
		return dp[st][ed];
	if(st > ed)
		return 0;
	int min = 999999999;
	
}

int main() {

	int t,c;
	int min;
	
	scanf("%d",&t);
	while(t--) {
		if(c)	puts("");
		else	c = 1;
		scanf("%s%*c",s+1);
		target = getchar();
		memset(dp,0,sizeof(dp));
		min = 999999999;
		min = go(1,n);
		if(min != 999999999) {
		
		} else {
			puts("None exist!");
		}
	}

	return 0;
}