#include <stdio.h>
#include <string.h>

int s[60][30],profit[60][30],coin[60][30];
int len[60],MAXL[60],num[60],ans[20],ansn;
bool dp[60][2000];

int main() {

	int t,i,j,k,max,sum,c=0,total;
	
	while(scanf("%d",&t) && t) {
	
		if(c)	puts("");
	
		memset(dp,0,sizeof(dp));
		memset(num,0,sizeof(num));
	
		sum = total = 0;
		for(i=1;i<=t;i++) {
			scanf("%d",&len[i]);
			total += len[i];
			for(j=1;j<=len[i];j++)
				scanf("%d",&s[i][j]);
		}
		
		for(i=1;i<=t;i++) {
			max = 0;
			for(j=1;j<=len[i];j++) {
				profit[i][j] = profit[i][j-1]+10-s[i][j];
				if(profit[i][j] > max)
					max = profit[i][j];
			}
			MAXL[i] = max;
			sum += max;
		}
		
		for(i=1;i<=t;i++) {
			if(MAXL[i] == 0)
				coin[i][num[i]++] = 0;
			for(j=1;j<=len[i];j++)
				if(profit[i][j] == MAXL[i])
					coin[i][num[i]++] = j;
		}
		
		dp[0][0] = true;
		for(i=1;i<=t;i++)
			for(j=0;j<num[i];j++)
				for(k=total;k>=coin[i][j];k--)
					if(dp[i-1][k-coin[i][j]])
						dp[i][k] = true;
		
		ansn = 0;
		for(i=0;ansn < 10 && i<=total;i++)
			if(dp[t][i])
				ans[ansn++] = i;
		
		printf("Workyards %d\n",++c);
		printf("Maximum profit is %d.\n",sum);
		printf("Number of pruls to buy:");
		for(i=0;i<ansn;i++)
			printf(" %d",ans[i]);
		puts("");
	}

	return 0;
}
