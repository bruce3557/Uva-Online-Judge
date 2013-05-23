#include <stdio.h>
#include <string.h>

int n,m,deg[110],ans[110],len;
char map[110][110],used[110];

void go(int now) {
	for(int i=1;i<=n;i++)
		if(used[i] == 0 && map[now][i]) {
			used[i] = 1;
			map[now][i]--;
			go(i);
			ans[len++] = i;
		}
}

int main() {
	int i,j;
	
	while(scanf("%d%d",&n,&m) && n+m) {
		memset(deg,0,sizeof(deg));
		memset(map,0,sizeof(map));
		memset(used,0,sizeof(used));
		while(m--) {
			scanf("%d%d",&i,&j);
			map[i][j] = 1;
			deg[j]++;
		}
		len = 0;
		for(i=1;i<=n;i++)
			if(used[i] == 0 && deg[i] == 0) {
				used[i] = 1;
				go(i);
				ans[len++] = i;
			}
		for(i=len-1;i>0;i--)
			printf("%d ",ans[i]);
		printf("%d\n",ans[i]);
	}

	return 0;
}
