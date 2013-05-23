#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#define MAX (999999999)
using std::priority_queue;

int n,m;
int len[2010], dist[2010];
char road[2010][60];
char city[2010][2][60];
char from[60], to[60];
bool used[2010];
bool ops[2010], opg[2010];

int elen;
int st[2010];
struct node {
	int u, v;
	
	bool operator < (const node &t) const {
		return (u < t.u);
	}
}e[4000010];

struct EE {
	int id, value;
	
	bool operator < (const EE &t) const {
		return  (value > t.value);
	}
};

int main() {
	
	while(scanf("%d",&n) && n) {
		memset(ops, 0, sizeof(ops));
		memset(opg, 0, sizeof(opg));
		scanf("%s%s",from,to);
		for(int i=0;i<n;++i) {
			scanf("%s%s%s", city[i][0], city[i][1], road[i]);
			len[i] = strlen(road[i]);
			if( !strcmp(city[i][0], from) || !strcmp(city[i][1], from) )	ops[i] = 1;
			if( !strcmp(city[i][0], to) || !strcmp(city[i][1], to) )		opg[i] = 1;
		}
		
		elen = 0;
		for(int i=0;i<n;++i)
			for(int j=i+1;j<n;++j)
				if( road[i][0] != road[j][0] && (!strcmp(city[i][0], city[j][0]) || !strcmp(city[i][0], city[j][1]) || !strcmp(city[i][1], city[j][0]) || !strcmp(city[i][1], city[j][1]))) {
					e[elen++] = (node){i, j};
					e[elen++] = (node){j, i};
				}
		
		std::sort(e, e+elen);
		for(int i=0;i<n;++i)
			st[i] = -1;
		for(int i=0;i<elen;++i)
			if(st[e[i].u] == -1)
				st[e[i].u] = i;
		st[n] = elen;
		for(int i=n-1;i>=0;--i)
			if(st[i] == -1)
				st[i] = st[i+1];
		
		for(int i=0;i<n;++i) {
			dist[i] = MAX;
			used[i] = 0;
		}
		
		priority_queue<EE> Q;
		for(int i=0;i<n;++i)
			if( ops[i] ) {
				dist[i] = len[i];
				Q.push((EE){i, dist[i]});
			}
		
		int minimum = MAX;
		for(int i=0;i<n;++i) {
			int ptr=-1;
			while( !Q.empty() ) {
				EE tp = Q.top();
				Q.pop();
				if(dist[tp.id] > minimum)	break;
				if( !used[tp.id] ) {
					ptr = tp.id;
					break;
				}
			}
			if(ptr == -1 || used[ptr] || dist[ptr] > minimum)	break;
			if(opg[ptr] && dist[ptr] < minimum)	minimum = dist[ptr];
			used[ptr] = 1;
			for(int j=st[ptr];j<st[ptr+1];++j)
				if(!used[e[j].v] && dist[e[j].v] > dist[ptr]+len[e[j].v]) {
					dist[e[j].v] = dist[ptr]+len[e[j].v];
					Q.push((EE){e[j].v, dist[e[j].v]});
				}
		}
		
		if(minimum >= MAX)
			puts("impossivel");
		else
			printf("%d\n",minimum);
	}
	
	return 0;
}
