#include <stdio.h>
#include <algorithm>

int n,m,len;
int dis[510],d[510],st[510];
char used[510],tmp[510];

struct node {
	int a,b,c;
	bool operator < (node t) const {
		return a < t.a;
	}
} edge[100100];

int main() {
	int i,j,k,min,minptr,max,ans,ansptr;
	int t,c=0;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&m);
		if(c)	puts("");
		else	c = 1;
		
		for(i=1;i<=m;i++)
			dis[i] = 99999999;
		for(i=0;i<n;i++) {
			scanf("%d",&j);
			dis[j] = 0;
		}
		
		len = 0;
		gets(tmp);
		while(gets(tmp) != NULL) {
			for(i=0;tmp[i] && (tmp[i] < '0' || tmp[i] > '9');i++);
			if(tmp[i] == '\0')	break;
			sscanf(tmp,"%d%d%d",&i,&j,&k);
			edge[len++] = (node){i,j,k};
			edge[len++] = (node){j,i,k};
		}
		
		std::sort(edge,edge+len);
		for(i=1;i<=m;i++)
			st[i] = -1;
		for(i=0;i<len;i++)
			if(st[edge[i].a] == -1)
				st[edge[i].a] = i;
		st[m+1] = len;
		for(i=m;i>0;i--)
			if(st[i] == -1)
				st[i] = st[i+1];
				
		ans = 99999999;
		for(k=1;k<=m;k++) {
			memset(used,0,sizeof(used));
			for(i=1;i<=m;i++)
				d[i] = dis[i];
			d[k] = 0;
			for(i=1;i<=m;i++) {
				min = 99999999;
				for(j=1;j<=m;j++)
					if(used[j] == 0 && min > d[j]) {
						min = d[j];
						minptr = j;
					}
				used[minptr] = 1;
				for(j=st[minptr];j<st[minptr+1];j++)
					if(used[edge[j].b] == 0 && d[minptr]+edge[j].c < d[edge[j].b])
						d[edge[j].b] = d[minptr]+edge[j].c;
			}
			max = -1;
			for(i=1;i<=m;i++)
				if(d[i] > max)
					max = d[i];
			if(max < ans) {
				ans = max;
				ansptr = k;
			}
		}
		
		printf("%d\n",ansptr);
	}
	
	return 0;
}
