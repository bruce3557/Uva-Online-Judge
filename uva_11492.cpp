#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using std::priority_queue;
const int MAX = 999999999;

int np, m;
int n, len;
int st[52010];
int dist[52010];
bool used[52010];
char city[4010][60];

struct node {
	int u, v, len;
	
	bool operator < (const node &t) const {
		return (u < t.u);
	}
} e[3000010];

struct EE {
	int id, value;
	
	bool operator < (const EE &t) const {
		return (value > t.value);
	}
};

inline int find(char *str) {
	for(int i=0;i<np;++i)
		if( !strcmp(str, city[i]) )
			return i;
	strcpy(city[np], str);
	return np++;
}

int main() {
	char source[60], dest[60];
	while(scanf("%d",&m) && m) {
		np = 0;
		len = 0;
		scanf("%s %s", source, dest);
		int from = find(source);
		int to = find(dest);
		for(int i=0;i<m;++i) {
			char l1[60], l2[60], word[60];
			scanf("%s%s%s",l1,l2,word);
			int type = word[0]-'a';
			int lent = strlen(word);
			int p1 = find(l1);
			int p2 = find(l2);
			for(int j=0;j<26;++j) {
				if(j == type)	continue;
				e[len++] = (node){p1*26+type, p2*26+j, lent};
				e[len++] = (node){p2*26+type, p1*26+j, lent};
			}
		}
		
		n = np*26;
		std::sort(e, e+len);
		for(int i=0;i<n;++i)
			st[i] = -1;
		for(int i=0;i<len;++i)
			if(st[e[i].u] == -1)
				st[e[i].u] = i;
		st[n] = len;
		for(int i=n-1;i>=0;--i)
			if(st[i] == -1)
				st[i] = st[i+1];
		
		for(int i=0;i<n;++i) {
			dist[i] = MAX;
			used[i] = 0;
		}
		//printf("%d %d %d %d\n",n, len,from,to);
		priority_queue<EE> Q;
		for(int i=0;i<26;++i) {
			dist[from*26+i] = 0;
			Q.push((EE){from*26+i, 0});
		}
		
		for(int i=0;i<n;++i) {
			int ptr=-1;
			while( !Q.empty() ) {
				EE tp = Q.top();
				Q.pop();
				if( !used[tp.id] ) {
					ptr = tp.id;
					break;
				}
			}
			if(ptr == -1 || used[ptr])	break;
			//printf("%s: %d\n",city[ptr/26],dist[ptr]);
			used[ptr] = 1;
			for(int j=st[ptr];j<st[ptr+1];++j)
				if(!used[e[j].v] && (dist[e[j].v] > dist[ptr]+e[j].len)) {
					dist[e[j].v] = dist[ptr]+e[j].len;
					Q.push((EE){e[j].v, dist[e[j].v]});
				}
		}
		
		int minimum = MAX;
		for(int i=0;i<26;++i)
			if(minimum > dist[to*26+i])
				minimum = dist[to*26+i];
		
		if(minimum >= MAX)
			puts("impossivel");
		else
			printf("%d\n",minimum);
	}
	
	return 0;
}
