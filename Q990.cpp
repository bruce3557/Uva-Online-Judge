#include <stdio.h>
#include <string.h>

struct node {
	int d,w;
} treasure[50];

int dp[3010],path[50][3010],ans[50];

int main() {
	
	int n,w,t,c=0;
	int i,j,max,max_ptr,num;
	
	while(scanf("%d%d",&n,&w) != EOF) {
		if(c)	puts("");
		else	c = 1;
		scanf("%d",&t);
		
		for(i=1;i<=t;i++) {
			scanf("%d%d",&treasure[i].d,&treasure[i].w);
			treasure[i].d *= 3*w;
		}
		
		memset(dp,0,sizeof(int)*(n+1));
		memset(path,0,sizeof(path));
		
		max = 0;
		for(i=t;i > 0;i--)
			for(j=n;j-treasure[i].d >= 0;j--)
				if(dp[j] < dp[j-treasure[i].d]+treasure[i].w) {
					dp[j] = dp[j-treasure[i].d]+treasure[i].w;
					path[i][j] = 1;
				}
		
		num = 0;
		printf("%d\n",dp[n]);
		for(i=1,j=n;dp[j] && i<=t;i++)
			if(path[i][j]) {
				ans[num++] = i;
				j -= treasure[i].d;
			}
		
		printf("%d\n",num);
		for(i=0;i<num;i++)
			printf("%d %d\n",treasure[ans[i]].d/(3*w),treasure[ans[i]].w);
	}
	
	return 0;
}
