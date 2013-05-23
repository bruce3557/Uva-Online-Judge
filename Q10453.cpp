#include <stdio.h>
#include <string.h>

int n,m;
char s[1010];
int dp[1010][1010],path[1010][1010];

int go(int i,int j) {
	if(dp[i][j] != -1)	return dp[i][j];
	if(i >= j)	return 0;
	
	if(s[i] == s[j]) {
		return (dp[i][j] = go(i+1,j-1));
	} else {
		int a,b;
		a = go(i+1,j);
		b = go(i,j-1);
		if(a < b) {
			dp[i][j] = a+1;
			path[i][j] = 1;
		} else {
			dp[i][j] = b+1;
			path[i][j] = 2;
		}
		return dp[i][j];
	}
}

void print(int i,int j) {
	if(i > j)	return;
	if(i == j) {
		printf("%c",s[i]);
		return;
	}
	if(s[i] == s[j]) {
		printf("%c",s[i]);
		print(i+1,j-1);
		printf("%c",s[j]);
	} else {
		if(path[i][j] == 1) {
			printf("%c",s[i]);
			print(i+1,j);
			printf("%c",s[i]);
		} else {
			printf("%c",s[j]);
			print(i,j-1);
			printf("%c",s[j]);
		}
	}
}

int main() {
	int i,j,len;
	
	while(gets(s) != NULL) {
		n = strlen(s);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				dp[i][j] = -1;
				path[i][j] = 0;
		len = go(0,n-1);
		printf("%d ",len);
		print(0,n-1);
		puts("");
	}

	return 0;
}
