#include <stdio.h>
#include <string.h>

int n,dp[1010][1010],len,Time[26],map[1010][26][2];
char s[1010],ans[1010];
bool cango[1010][1010][26];

int go(int st,int ed) {
	if(st > ed)	return dp[st][ed] = 0;
	if(st == ed)	return dp[st][ed] = 1;
	if(dp[st][ed])	return dp[st][ed];
	if(s[st] == s[ed])
		return dp[st][ed] = 2+go(st+1,ed-1);
	else {
		int t1,t2,max;
		t1 = go(st+1,ed);
		t2 = go(st,ed-1);
		max = t1>t2?t1:t2;
		return dp[st][ed] = max;
	}
}

bool gogo(int num,int st,int ed) {
	int i;
	if(num == 0)	return true;
	if(st > ed)	return false;
	if(num == 1) {
		int min = 99999;
		for(i=st;i<=ed;i++)
			if(min > s[i])
				min = s[i];
		ans[len++] = min;
		return true;
	}
	for(i='a';i<='z';i++) {
		int a,b;
		a = map[st][i-'a'][1], b = map[ed][i-'a'][0];
		if(a > ed || b < st || a > b)	continue;
		if(dp[a][b] == num) {
			ans[len++] = i;
			gogo(num-2,a+1,b-1);
			return true;
		}
	}
	return false;
}

int main() {
	int i,j,k,max;
	
	while(gets(s+1) != NULL) {
		memset(dp,0,sizeof(dp));
		memset(map,0,sizeof(map));
		n = strlen(s+1);
		for(i=1;i<=n;i++) {
			for(j=0;j<26;j++) {
				for(k=i;k>0;k--)
					if(s[k] == j+'a')	break;
				map[i][j][0] = k;
				for(k=i;k<=n;k++)
					if(s[k] == j+'a')	break;
				map[i][j][1] = k;
			}
		}
		
		len = 0;
		max = go(1,n);
		gogo(max,1,n);
		
		for(i=0;i<len;i++)
			printf("%c",ans[i]);
		if(max % 2)	i = len-2;
		else		i = len-1;
		for(;i>=0;i--)
			printf("%c",ans[i]);
		puts("");
	}

	return 0;
}
