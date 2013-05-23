#include <stdio.h>
#include <algorithm>
int n,m,ans;

struct edge {
	int a,b;
} e[100010];

int s[100010];

int Union(int now) {
	if(s[now] == now)	return now;
	return s[now] = Union(s[now]);
}

int main() {
	int i,j,t,k,ans;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			s[i] = i;
		for(i=0;i<m;i++) {
			scanf("%d%d",&j,&k);
			e[i] = (edge){j,k};
			s[Union(j)] = Union(k);
		}
		ans = 0;
		for(i=1;i<=n;i++)
			Union(i);
		for(i=1;i<=n;i++)
			if(s[i] == i)
				ans++;
		printf("%d\n",ans);
	}
	
	return 0;
}
