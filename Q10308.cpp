#include <stdio.h>
#include <string.h>
#include <algorithm>

int st[10010],dp[20010],n,m,ans;
char used[10010];
struct node {
	int a,b,c;
	
	bool operator < (const node &t) const {
		return a < t.a;
	}
} e[20010];

int go(int now) {
	if(dp[now] != -1)	return dp[now];
	int i,sum,max,tmp;
	max = e[now].c;
	sum = e[now].c;
	for(i=st[e[now].b];i<st[e[now].b+1];i++) {
		if(used[e[i].b] == 0) {
			used[e[i].b] = 1;
			tmp = go(i);
			if(tmp+sum > max)	max = tmp+sum;
			used[e[i].b] = 0;
		}
	}
	return dp[now] = max;
}

void Solve() {
	int i;	
	std::sort(e,e+m);
	for(i=1;i<=n;i++)
		st[i] = -1;
	for(i=0;i<m;i++)
		if(st[e[i].a] == -1)
			st[e[i].a] = i;
	st[n+1] = m;
	for(i=n;i>0;i--)
		if(st[i] == -1)
			st[i] = st[i+1];
	for(i=0;i<m;i++)
		dp[i] = -1;
	memset(used,0,sizeof(used));
	for(i=0;i<m;i++) {
		used[e[i].a] = used[e[i].b] = 1;
		go(i);
		used[e[i].a] = used[e[i].b] = 0;
	}
	for(i=0;i<m;i++)
		if(ans < dp[i])
			ans = dp[i];
}

bool Build() {
	int i,j,k;
	char s[200];
	memset(used,0,sizeof(used));
	ans = n = m = 0;
	while(1) {
		if(gets(s) == NULL) {
			Solve();
			printf("%d\n",ans);
			return false;
		}
		if(s[0] == '\0')	return true;
		sscanf(s,"%d%d%d",&i,&j,&k);
		if(used[i] == 0)	n++,used[i] = 1;
		if(used[j] == 0)	n++,used[j] = 1;
		e[m++] = (node){i,j,k};
		e[m++] = (node){j,i,k};
	}
}

int main() {
	
	while( Build() ) {
		Solve();
		printf("%d\n",ans);
	}
	
	return 0;
}
