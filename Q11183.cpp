#include <stdio.h>
#include <string.h>
#define inf (-1)

int n,m;
int dist[1010];
int map[1010][1010];
char used[1010];

int main() {
	int t,c=0;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;++j)
				map[i][j] = inf;
		
		for(int i=0;i<m;i++) {
			int a,b,cost;
			scanf("%d%d",&a,&b,&cost);
			map[a][b] = map[b][a] = cost;
		}
		
		int sum = 0;
		for(int i=0;i<n;i++) {
			dist[i] = inf;
			used[i] = 0;
		}
		dist[0] = 0;
		for(int i=0;i<n;i++) {
			int minp = inf;
			for(int j=0;j<n;j++) {
				if(!used[j] && dist[j] != inf) {
					if(minp == inf)	minp = j;
					else if(dist[j] < dist[minp])	minp = j;
				}
			}
			if(minp == inf)	break;
			used[minp] = 0;
			for(int j=0;j<n;j++)
				if(!used[j] && map[minp][j] != inf) {
					if(dist[j] == inf)
						dist[j] = dist[minp]+map[minp][j];
					else if(dist[j] > dist[minp]+map[minp][j])
						dist[j] = dist[minp]+map[minp][j];
				}
		}
		
		bool flag = false;
		for(int i=0;i<n;i++)
			if(dist[i] == inf) {
				flag = true;
				break;
			}
		
		printf("Case #%d: ",++c);
		if( !flag )
			puts("Possums!");
		else
			printf("%d\n",sum);
	}
	
	return 0;
}
