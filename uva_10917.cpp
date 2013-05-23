#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#define INF (1000000010)
using std::queue;

int n,m;
int map[1010][1010];
int st[1010];
int d[1010];
int ways[1010];
bool used[1010];

bool cmp(int a,int b) {
	return (d[a] < d[b]);
}

int main() {

	while(scanf("%d",&n) && n) {
		scanf("%d",&m);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				map[i][j] = INF;
		for(int i=0;i<m;++i) {
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			map[a][b] = map[b][a] = c;
		}
		
		for(int i=1;i<=n;++i) {
			d[i] = INF;
			used[i] = 0;
		}
		
		d[2] = 0;
		for(int i=0;i<n;++i) {
			int ptr = -1;
			for(int j=1;j<=n;++j) {
				if(used[j] || d[j] >= INF)	continue;
				if(ptr == -1 || d[j] < d[ptr])	ptr = j;
			}
			if(ptr == -1 || used[ptr])	break;
			used[ptr] = 1;
			for(int j=1;j<=n;++j)
				if(used[j] == 0 && d[j] > d[ptr]+map[ptr][j])
					d[j] = d[ptr]+map[ptr][j];			
		}

		memset(ways,0,sizeof(ways));
		for(int i=1;i<=n;++i)
			st[i] = i;
		std::sort(st+1,st+1+n,cmp);
		ways[2] = 1;
		for(int i=2;i<=n;++i) {
			for(int j=1;j<i;++j)
				if(d[st[j]] < d[st[i]] && map[st[j]][st[i]] < INF)
					ways[st[i]] += ways[st[j]];
		}
		
		printf("%d\n",ways[1]);
	}

	return 0;
}
