#include <stdio.h>
#include <string.h>
#include <algorithm>

int n,m,st[100010],str[100010],used[100010],counter,dfn[100010],fin[100010],Time,deg[100010];

struct node {
	int a,b;
	
	bool operator < (const node &t) const {
		return a<t.a;
	}
} e[100010],eg[100010],pp[100010];

void go(int now) {
	Time++;
	dfn[now] = Time;
	for(int i=st[now];i<st[now+1];i++)
		if(dfn[e[i].b] == -1)
			go(e[i].b);
	Time++;
	fin[now] = Time;
}

void gogo(int now) {
	used[now] = counter;
	for(int i=str[now];i<str[now+1];i++)
		if(used[eg[i].b] == 0)
			gogo(eg[i].b);
}

int main() {
	int i,j,t;
	
	scanf("%d",&t);
	while(t--) {
		memset(used,0,sizeof(used));
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++) {
			scanf("%d%d",&e[i].a,&e[i].b);
			eg[i] = (node){e[i].b,e[i].a};
		}
		
		for(i=1;i<=n;i++)
			st[i] = str[i] = -1;
		std::sort(e,e+m);
		std::sort(eg,eg+m);
		for(i=0;i<m;i++) {
			if(st[e[i].a] == -1)
				st[e[i].a] = i;
			if(str[eg[i].a] == -1)
				str[eg[i].a] = i;
		}
		st[n+1] = str[n+1] = m;
		for(i=n;i>0;i--) {
			if(st[i] == -1)
				st[i] = st[i+1];
			if(str[i] == -1)
				str[i] = str[i+1];
		}
		
		for(i=1;i<=n;i++)
			dfn[i] = fin[i] = -1;
		Time = counter = 0;
		for(i=1;i<=n;i++)
			if(dfn[i] == -1)
				go(i);
		for(i=1;i<=n;i++)
			pp[i] = (node){fin[i],i};
		std::sort(pp+1,pp+1+n);
		memset(dfn,0,sizeof(dfn));
		for(i=n;i>0;i--)
			if(used[pp[i].b] == 0) {
				counter++;
				gogo(pp[i].b);
			}
		
		memset(deg,0,sizeof(deg));
		for(i=0;i<m;i++)
			if(used[e[i].a] != used[e[i].b])
				deg[used[e[i].b]]++;
		
		int ans = 0;
		for(i=1;i<=counter;i++)
			if(deg[i] == 0)
				ans++;
				
		printf("%d\n",ans);	
	}
	
	return 0;
}
