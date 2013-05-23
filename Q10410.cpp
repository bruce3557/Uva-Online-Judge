#include <stdio.h>
#include <string.h>

int n,f[1010],dfs[1010],bfs[1010],posd[1010];

void find(int now,int p) {
	int b,d,i,min=n+1,minptr=0;
	i = posd[bfs[p]];
	for(b=now;b>0;b--) {
		d = posd[bfs[b]];
		if(d < i && i-d < min) {
			min = i-d;
			minptr = b;
		}
	}
	f[p] = bfs[minptr];
}

void go(int now) {
	if(now > n)	return;
	int cnt,i;
	for(cnt=now+2;cnt<=n && bfs[cnt]>bfs[cnt-1];cnt++);  //§ä¤W¤É§Ç¦C
	for(i=now+2;i<cnt;i++)
		if(posd[bfs[i]] < posd[bfs[i-1]])
			break;
	cnt = i;
	for(i=now+1;i<cnt;i++)
		if(f[i] == 0)
			find(now,i);									 //©w¦ìª¨ª¨
	go(cnt-1);
}

int main() {
	int i,j;
	
	while(scanf("%d",&n) != EOF) {
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++)
			scanf("%d",bfs+i);
		for(i=1;i<=n;i++)
			scanf("%d",dfs+i);
		for(i=1;i<=n;i++)
			posd[dfs[i]] = i;
		
		go(1);
		for(i=1;i<=n;i++,puts("")) {
			printf("%d:",i);
			for(j=1;j<=n;j++)
				if(f[j] == i)
					printf(" %d",bfs[j]);
		}
	}	
	
	return 0;
}
