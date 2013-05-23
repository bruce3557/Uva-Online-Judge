#include <stdio.h>
#include <string.h>

int n,m,pre[110];
long long map[110][110];

long long MaxFlow() {
	int i,j,k,q[1100];
	long long sum = 0,min;
	while(1) {
		for(i=1;i<=2*n;i++)
			pre[i] = -1;
		q[0] = 1;
		pre[1] = 1;
		i = 0, j = 1;
		while(i < j) {
			if(q[i] == 2*n)	break;
			for(k=1;k<=2*n;k++)
				if(pre[k] == -1 && map[q[i]][k] > 0) {
					pre[k] = q[i];
					q[j++] = k;
				}
			i++;
		}
		if(i >= j)	return sum;
		min = 20000000000LL;
		for(k=2*n;pre[k] != k;k = pre[k])
			if(min > map[pre[k]][k])
				min = map[pre[k]][k];
		for(k=2*n;pre[k] != k;k = pre[k]) {
			map[pre[k]][k] -= min;
			map[k][pre[k]] += min;
		}
		sum += min;
	}
}

int main() {
	int i,j,k;
	
	while(scanf("%d%d",&n,&m) && n+m) {
		memset(map,0,sizeof(map));
		map[1][n+1] = map[n+1][1] = map[2*n][n] = map[n][2*n] = 20000000000LL;
		for(i=2;i<n;i++) {
			scanf("%d%d",&j,&k);
			map[j][j+n] = map[n+j][j] = k;
		}
		
		while(m--) {
			scanf("%d%d%d",&i,&j,&k);
			map[i+n][j] = map[j+n][i] = k;
		}
		
		printf("%lld\n",MaxFlow());
	}
	
	return 0;
}
