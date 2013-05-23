#include <stdio.h>
#include <string.h>

struct node {
	int p,w;
} s[1010];

int dp[30010];

int main() {
	
	int t,n,m,g;
	int i,j,sum;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		
		for(i=0;i<n;i++)
			scanf("%d%d",&s[i].p,&s[i].w);
		
		scanf("%d",&m);
		
		sum = 0;
		while(m--) {
			scanf("%d",&g);
			memset(dp,0,sizeof(int)*(g+1));
		
			for(i=0;i<n;i++)
				for(j=g;j>=s[i].w;j--)
					if(dp[j] < dp[j-s[i].w]+s[i].p)
						dp[j] = dp[j-s[i].w]+s[i].p;	
			
			sum += dp[g];
		}
		
		printf("%d\n",sum);
	}
	
	return 0;
}
