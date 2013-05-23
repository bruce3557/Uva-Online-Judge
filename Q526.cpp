#include <stdio.h>
#include <string.h>
#define MAX 999999999

int dp[110][110],n,m,path[110][110],insert,del;
char s[110],t[110];

int go(int i,int j) {
	if(i <= 0 && j <= 0)	return 0;
	if(j <= 0) {
		path[i][j] = 3;
		return dp[i][j] = go(i-1,j)+1;
	}
	if(i <= 0) {
		path[i][j] = 2;
		return dp[i][j] = go(i,j-1)+1;
	}
	if(dp[i][j] != MAX)	return dp[i][j];
	int min,tmp;
	min = MAX;
	if(s[i] == t[j]) {
		tmp = go(i-1,j-1);
		path[i][j] = 4;
		return dp[i][j] = tmp;
	}
	
	tmp = go(i-1,j)+1;
	if(min > tmp) {
		min = tmp;
		path[i][j] = 3;
	}

	tmp = go(i,j-1)+1;
	if(min > tmp) {
		min = tmp;
		path[i][j] = 2;
	}
	
	tmp = go(i-1,j-1)+1;
	if(min > tmp) {
		min = tmp;
		path[i][j] = 1;
	}
	
	return dp[i][j] = min;
}

void print(int i,int j,int num) {
	if(num <= 0)	return;
	if(path[i][j] == 1) {
		print(i-1,j-1,num-1);
		printf("%d Replace %d,%c\n",num,i+insert-del,t[j]);
	} else if(path[i][j] == 2) {
		print(i,j-1,num-1);
		insert++;
		printf("%d Insert %d,%c\n",num,i+insert-del,t[j]);
	} else if(path[i][j] == 3) {
		print(i-1,j,num-1);
		printf("%d Delete %d\n",num,i+insert-del);
		del++;
	} else if(path[i][j] == 4) {
		print(i-1,j-1,num);
	}
}

int main() {
	int i,j,c=0;
	
	while(gets(s+1) != NULL) {
		gets(t+1);
		if(c)	puts("");
		else	c = 1;
		n = strlen(s+1);
		m = strlen(t+1);
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				dp[i][j] = MAX;
		insert = del = 0;
		memset(path,0,sizeof(path));
		printf("%d\n",go(n,m));
		print(n,m,dp[n][m]);
	}
	
	return 0;
}
