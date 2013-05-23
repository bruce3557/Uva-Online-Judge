#include <stdio.h>
#include <string.h>

int n,min,deg[20];
char used[20],map[20][20],u[20];

void DFS(int now) {
	for(int i=1;i<=n;i++)
		if(u[i] == 0 && used[i] != 2 && map[now][i]) {
			u[i] = 1;
			DFS(i);
		}
}

void go(int now,int len) {
	if(now > n) {
		int i,j,sum;
		memset(deg,0,sizeof(deg));
		memset(u,0,sizeof(u));
		for(i=1;i<=n;i++)
			if(used[i] == 0)
				for(j=1;j<i;j++)
					if(used[j] == 0 && map[i][j]) {
						deg[i]++;
						deg[j]++;
					}
		for(i=1;i<=n;i++)
			if(deg[i] > 2)
				return;
		sum = 0;
		for(i=1;i<=n;i++) {
			if(used[i] == 0) { 
				if(deg[i] <= 1 && u[i] == 0) {
					u[i] = 1;
					DFS(i);
					sum++;
				}
			}
		}
		for(i=1;i<=n;i++)
			if(used[i] != 2 && u[i] == 0)
				return;
		if(len >= sum-1 && len < min)
			min = len;
		return;
	}
	go(now+1,len);
	
	used[now] = 2;
	go(now+1,len+1);
	used[now] = 0;
}

int main() {
	int c=0;
	int i,j;
	
	while(scanf("%d",&n) && n) {
		memset(used,0,sizeof(used));
		memset(map,0,sizeof(map));
		while(scanf("%d%d",&i,&j) && i != -1 && j != -1)
			map[i][j] = map[j][i] = 1;
		min = 999999;
		go(1,0);
		printf("Set %d: Minimum links to open is %d\n",++c,min);
	}

	return 0;
}
