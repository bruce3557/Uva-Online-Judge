#include <stdio.h>
#include <string.h>

int n,m;
int map[110][110],cost[110][110];

int main() {
	
	while(scanf("%d%d",&n,&m) != EOF) {
		memset(map,0,sizeof(map));
		for(i=0;i<110;i++)
			for(j=0;j<110;j++)
				cost[i][j] = 99999999;
		
		for(i=0;i<m;i++) {
			int j,k,cc;
			scanf("%d%d%d",&j,&k,&cc);
			map[j][k] = map[k][j] = 1;
			cost[j][k] = cc;
			cost[k][j] = -cc;
		}
		
		int total,limit;
		scanf("%d %d",&total,&limit);
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				if(map[i][j] == 1)
					map[i][j] = map[j][i] = limit;
		
		map[0][n+1] = map[n+2][n+3] = total;
		cost[0][n+1] = 0;
	}
	
	return 0;
}
