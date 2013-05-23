#include <stdio.h>

int n,m,visit[110];

struct node {
	int a,b;
} edge[30010];

int Union(int now) {
	if(now == visit[now])	return now;
	return visit[now] = Union(visit[now]);
}

int main() {
	int i,j,ans,num;
	char c;
	
	while(scanf("%d",&n) && n) {
		m = num = 0;
		while(scanf("%d%c",&i,&c) && i) {
			while(scanf("%d%c",&j,&c)) {
				edge[m++] = (node){i,j};
				edge[m++] = (node){j,i};
				if(c == '\n')	break;
			}
		}
		
		for(i=1;i<=n;i++) {
			for(j=1;j<=n;j++)
				visit[j] = j;
			for(j=0;j<m;j++)
				if(edge[j].a != i && edge[j].b != i && visit[edge[j].a] != visit[edge[j].b]) {
					visit[Union(edge[j].b)] = Union(edge[j].a);
					Union(edge[j].b);
				}
			for(j=1;j<=n;j++)
				Union(j);
			if(i == 1)	ans = visit[2];
			else		ans = visit[1];
			for(j=1;j<=n;j++)
				if(j!=i && visit[j] != ans)
					break;
			if(j <= n)	num++;
		}
		printf("%d\n",num);
	}

	return 0;
}
