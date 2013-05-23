#include <stdio.h>
#include <string.h>
#include <algorithm>

int n,m,k,ans;
int st[10010];
int fall[10010];
bool used[10010];
struct node {
	int a,b;
	bool operator < (const node &t) const {
		return a < t.a;
	}
} e[10010];

void go(int now) {
	used[now] = 1;
	ans++;
	for(int i=st[now];i<st[now+1];i++)
		if(!used[e[i].b])
			go(e[i].b);
}

int main() {
	int t;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<=n;i++) {
			st[i] = -1;
			used[i] = false;
		}
		for(int i=0;i<m;i++)
			scanf("%d%d",&e[i].a,&e[i].b);
		std::sort(e,e+m);
		for(int i=0;i<m;i++)
			if(st[e[i].a] == -1)
				st[e[i].a] = i;
		st[n+1] = m;
		for(int i=n;i>0;--i)
			if(st[i] == -1)
				st[i] = st[i+1];
		
		for(int i=0;i<k;i++)
			scanf("%d",fall+i);
		
		ans = 0;
		for(int i=0;i<k;i++)
			if( !used[fall[i]] )
				go(fall[i]);
		
		printf("%d\n",ans);
	}
	
	return 0;
}
