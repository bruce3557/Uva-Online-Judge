#include <stdio.h>
#include <string.h>
#include <algorithm>

int n,m,st[210],color[210],cnt;
struct node {
	int a,b;
	
	bool operator < (const node &t) const {
		return a<t.a;
	}
} e[20010];

void go(int now,int c) {
	int i;
	used[c] = 1;
	for(i=st[now];i<st[now+1];i++)
		if(used[e[i].b] == 0) {
		
		}
}

int main() {
	int t,i,j;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		m *= 2;
		for(i=0;i<m;i+=2) {
			scanf("%d%d",&e[i].a,&e[i].b);
			e[i+1] = (node){e[i].b,e[i].a};
		}
		std::sort(e,e+m);
		for(i=n-1;i>=0;i--)
			st[i] = -1;
		for(i=0;i<m;i++)
			if(st[e[i].a] == -1)
				st[e[i].a] = i;
		st[n] = m;
		for(i=n-1;i>=0;i--)
			if(st[i] == -1)
				st[i] = st[i+1];
		
		cnt = 0;
		memset(color,0,sizeof(color));
		for(i=0;i<n;i++)
			if(color[i] == 0) {
				go(i,1);
				if(cnt)	break;
			}
		
		if(cnt) {
			puts("-1");
		} else {
		
		}
	}
	
	return 0;
}
