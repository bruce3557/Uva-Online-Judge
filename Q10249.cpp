#include <stdio.h>
#include <string.h>

int map[150][150],n,m,num,start,end;
int pre[150],q[150];

int Min(int x,int y) {
	return x < y ? x : y;
}

int MaxFlow(int st,int ed) {
	int sum=0,i,j,k,a,b;
	while(1) {
		for(i=start;i<=end;i++)
			pre[i] = -1;
		q[0] = st;
		i = 0, j = 1;
		while(i < j) {
			if(q[i] == ed)	break;
			if(q[i] == st)
				a = 1, b = n;
			else if(q[i] <= n)
				a = n+1, b = n+m;
			else
				a = st, b = ed;
			for(k=a;k<=b;k++)
				if(pre[k] == -1 && map[q[i]][k] > 0) {
					pre[k] = q[i];
					q[j++] = k;
				}
			i++;
		}
		if(i >= j)	return sum;
		sum++;
		for(k=ed;k!=st;k=pre[k]) {
			map[pre[k]][k]--;
			map[k][pre[k]]++;
		}
	}
}

int main() {
	int i,j,total;
	
	while(scanf("%d%d",&n,&m) && n+m) {
		memset(map,0,sizeof(map));
		total = 0;
		for(i=1;i<=n;i++) {
			scanf("%d",&j);
			map[0][i] = j;
			total += j;
		}
		for(i=1;i<=m;i++) {
			scanf("%d",&j);
			map[i+n][n+m+1] = j;
		}
		for(i=1;i<=n;i++) 
			for(j=1;j<=m;j++)
				map[i][j+n] = 1;
		num = n+m+1;
		start = 0, end = num;
		int sum = MaxFlow(0,num);
		
		if(sum != total) {
			puts("0");
			continue;
		}
		
		puts("1");
		for(i=1;i<=n;i++) {
			for(j=1;j<=m;j++)
				if(map[j+n][i] > 0) {
					printf("%d",j);
					break;
				}
			for(j++;j<=m;j++)
				if(map[j+n][i] > 0)
					printf(" %d",j);
			puts("");
		}
	}
	
	return 0;
}
