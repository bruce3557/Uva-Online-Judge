#include <stdio.h>
#include <string.h>
#include <algorithm>

struct node {
	int a,b;
	bool operator < (node t) const {
		return (a < t.a || (a == t.a && b < t.b));
	}
} edge[10000];

int n,m,r[2000],path[2000];
char used[10000];

char go(int now,int ed,int len) {
	
	if(now == ed) {
		printf("ans: ");
		for(int i=1;i<len-1;i++)
			printf("%d ",path[i]);
		printf("%d\n",ed);
		return 1;
	}
	
	int flag;
	for(int i=r[now];i<r[now+1];i++) {
	
		if(used[edge[i].b] == 0) {
		
			if(path[len-2] != edge[i].b){
				printf("%d %d \n",now,edge[i].b);
				flag = 0;
				path[len] = edge[i].b;
				used[edge[i].b] = 1;
				flag = go(edge[i].b,ed,len+1);
				if(flag == 1)		return 1;
				else if(flag == -1)	return -1;
				used[edge[i].b] = 0;
			}
			
		} else {
			return -1;
		}
		
	}
	
	return 0;
}

int main() {

	int t,i,st;
	
	scanf("%d",&t);
	
	while(t--) {
		
		scanf("%d%d%d",&n,&m,&st);
		
		m *= 2;
		for(i=0;i<m;i+=2) {
			scanf("%d%d",&edge[i].a,&edge[i].b);
			edge[i+1] = (node) { edge[i].b, edge[i].a };
		}
		
		std::sort(edge,edge+m);
		
		for(i=0;i<=n;i++)
			r[i] = -1;
		
		for(i=0;i<m;i++)
			if(r[edge[i].a] == -1)
				r[edge[i].a] = i;
		r[n] = m;
		
		path[0] = -1;
		for(i=0;i<n;i++) {
			memset(used,0,sizeof(used));
			/*used[st] = 1,*/ path[1] = st;
			if(go(st,i,2) != 1)
				printf("%d No drive\n",i);
		}
		
	}

	return 0;
}
