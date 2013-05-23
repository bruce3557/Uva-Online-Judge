#include <stdio.h>

struct node {
	int x,y,num,cnt;
} q[10010];

int n,m,dis[110],dp[110][110],l[110],r[110];
char map[110][110],used[110][110];

int Min(int a,int b) {
	return a<b?a:b;
}

int Max(int a,int b) {
	return a>b?a:b;
}

int abs(int x) {
	if(x < 0)	return -x;
	return x;
}

int main() {
	int t,i,j,k;
	int x,y,sum,pre;
	
	scanf("%d",&t);
	while(t--) {
		memset(used,0,sizeof(used));
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%s",map[i]);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				map[i][j] -= '0';
		for(i=0;i<n;i++) {
			if(i%2)	dis[i] = -1;
			else	dis[i] = 99999999;
		}
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(map[i][j]%2 == 0) {
					if(i%2 == 0)
						dis[i] = Max(dis[i],j);
					else
						dis[i] = Min(dis[i],j);
				}
		for(i=n-1;i>=0;i--) {
			if(i%2) {
				if(dis[i] != 99999999)	break;
			} else {
				if(dis[i] != -1)		break;
			}
		}
		if(i < 0) {
			puts("0");
			continue;
		}
		sum = k = i;
		pre = 0;
		for(i=0;i<=k;i++) {
			if(i%2) {
				if(dis[i] != 99999
			} else {
			
			}
		}
		printf("%d\n",sum);
	}
	
	return 0;
}
