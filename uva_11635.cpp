#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

struct node {
	int a,b,len;
	
	bool operator < (node t) const {
		return a < t.a;
	}
} e[200100];

struct test {
	int num,dis;
	
	bool operator < (test t) const {
		return dis > t.dis;
	}
};

struct gogo {
	int node,cnt;
} q[10010];

int n,m,k,map[150][150],rest[150],st[10100],dis[10100];
char used[10100];

void Dijkstra(int start) {
	int i,j,t;
	std::priority_queue<test> que;
	
	t = rest[start];
	for(i=1;i<=n;i++)
		dis[i] = 999999999;
	dis[t] = 0;
	que.push((test){t,0});
	
	memset(used,0,sizeof(used));
	for(i=1;i<n;i++) {
		test tmp = (test){0,0};
		while(que.empty() == 0) {
			tmp = que.top();
			que.pop();
			if(used[tmp.num] == 0) break;
		}
		if(tmp.num == 0)	break;
		used[tmp.num] = 1;
		for(j=st[tmp.num];j<st[tmp.num+1];j++)
			if(used[e[j].b] == 0 && dis[e[j].b] > dis[e[j].a]+e[j].len && dis[e[j].a]+e[j].len <= 600) {
				dis[e[j].b] = dis[e[j].a]+e[j].len;
				que.push((test){e[j].b,dis[e[j].b]});
			}
	}
	
	for(i=0;i<k;i++) {
		if(i == start)	continue;
		if(dis[rest[i]] <= 600)
			map[start][i] = map[i][start] = 1;
	}
}

int main() {
	int i,j,d,a;
	
	while(scanf("%d",&n) && n) {
		scanf("%d",&k);
		for(i=0;i<k;i++)
			scanf("%d",rest+i);
		rest[k] = 1, rest[k+1] = n;
		k += 2;
		
		scanf("%d",&m);
		m *= 2;
		for(i=0;i<m;i+=2) {
			scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].len);
			e[i+1] = (node){e[i].b,e[i].a,e[i].len};
		}
		std::sort(e,e+m);
		for(i=1;i<=n;i++)
			st[i] = -1;
		for(i=0;i<m;i++)
			if(st[e[i].a] == -1)
				st[e[i].a] = i;
		st[n+1] = m;
		
		memset(map,0,sizeof(map));
		for(i=0;i<k;i++)
			Dijkstra(i);
		
		memset(used,0,sizeof(used));
		q[0] = (gogo){k-2,0};
		i = 0, j = 1;
		used[k-2] = 1;
		while(i < j) {
			a = q[i].node;
			if(a == k-1)	break;
			for(d=0;d<k;d++)
				if(used[d] == 0 && map[a][d]) {
					used[d] = 1;
					q[j++] = (gogo){d,q[i].cnt+1};
				}
			i++;
		}
		
		if(i >= j)
			puts("-1");
		else
			printf("%d\n",q[i].cnt-1);
	}	
	
	return 0;
}
