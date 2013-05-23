#include <stdio.h>
#include <string.h>

int n,m,ans,dp[110],deg[110];
char map[110][110],used[110];

void Build() {
	int i,j,k;
	memset(map,0,sizeof(map));
	memset(deg,0,sizeof(deg));
	for(i=1;i<=n;i++) {
		scanf("%d",&m);
		for(j=0;j<m;j++) {
			scanf("%d",&k);
			map[i][k] = 1;
			deg[k]++;
		}
	}
}

void go(int now) {
	used[now] = 1;
	int i;
	for(i=1;i<=n;i++)
		if(used[i] == 0 && map[now][i])
			go(i);
}	

void Solve() {
	int i,j;
	memset(used,0,sizeof(used));
	ans = -1;
	for(i=1;i<=n;i++)
		if(deg[i] == 0) {
			int sum = 0;
			memset(used,0,sizeof(used));
			used[i] = 1;
			go(i);
			used[i] = 0;
			for(j=1;j<=n;j++)
				if(used[j]) 
					sum++;
			dp[i] = sum;
			if(ans == -1 || sum > dp[ans])	ans = i;
		}
}

int main() {
	
	while(scanf("%d",&n) && n) {
		Build();
		Solve();
		printf("%d\n",ans);
	}
	
	return 0;
}
