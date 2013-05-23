#include <stdio.h>
#include <string.h>

char s[1010],t[1010],ans[1010];
int LCS[1010][1010],n,max,f[1010],l[1010];

void go(int st,int ed,int pos,int len) {
	int i,j,k;
	if(len <= 0) {
	
	}
	if(len == 1) {
		ans[max] = '\0';
		for(i=st;i<=ed;i++)
			if(
	}
	
	for(i='a';i<='z';i++) {
		for(j=st;j<=ed;j++)
			if(s[j] == i)
				for(=
	}
}

int main() {

	int i,j;
	
	while(gets(s+1) != NULL) {
		n = strlen(s+1);
		memset(LCS,0,sizeof(LCS));
		memset(f,0,sizeof(f));
		memest(l,0,sizeof(l));
		
		for(i=1;i<=n;i++)
			t[i] = s[n-i+1];
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++) {
				if(s[i] == t[j])
					LCS[i][j] = LCS[i-1][j-1]+1;
				else if(LCS[i-1][j] >= LCS[i][j-1])
					LCS[i][j] = LCS[i-1][j];
				else if(LCS[i][j-1] > LCS[i-1][j])
					LCS[i][j] = LCS[i][j-1];
			}
		
		printf("%d\n",LCS[n][n]);
		max = LCS[n][n];
		go(1,n,0,max);
		puts(ans);
	}

	return 0;
}
