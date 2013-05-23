/*Maximum Flow Problem
**Ford-Fulkerson Algorithm(DFS)
*/

#include <stdio.h>
#include <string.h>

int n,min;
int map[110][110],pre[110];

int find_path(int now,int ed){
	if(now == ed)	return 1;
	int i;
	for(i = 1;i <= n; i++)
		if(pre[i] == 0 && map[now][i] > 0){
			if( min > map[now][i] )
				min = map[now][i];
			pre[i] = now;
			if( find_path(i,ed) == 1 ){
				map[now][i] -= min;
				map[i][now] += min;
				return 1;
			}
		}
	return 0;
}

inline int FLOW(int st,int ed){
	int i,sum = 0;
	while(1){
		for(i=1;i<=n;i++)
			pre[i] = 0;
		min = 999999999;
		pre[st] = 1;
		if( find_path(st,ed) == 0 )	return sum;
		sum += min;
	} 
}

int main(){
	int i,j,m,cap,c = 0,st,ed;
	while(scanf("%d",&n) && n > 0){
		
		for(i = 1;i <= n; i++)
			for(j = 1;j <= n; j++)
				map[i][j] = 0;
		
		scanf("%d%d%d",&st,&ed,&m);

		while(m--){
			scanf("%d%d%d",&i,&j,&cap);
			map[i][j] += cap;
			map[j][i] += cap;
		}

		printf("Network %d\nThe bandwidth is %d.\n\n",++c,FLOW(st,ed));		
	}
	return 0;
}
