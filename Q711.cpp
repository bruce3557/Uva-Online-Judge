#include <stdio.h>
#include <string.h>

int coin[10];
bool dp[1200010];

int main() {
	int sum,c=0;
	int i,j,k;
	
	while(scanf("%d%d%d%d%d%d",coin+1,coin+2,coin+3,coin+4,coin+5,coin+6) && coin[1]+coin[2]+coin[3]+coin[4]+coin[5]+coin[6]) {
		
		sum = 0;
		memset(dp,0,sizeof(dp));
		
	    for(i=1;i<=6;i++)
			sum += i*coin[i];
			
		if(c)	puts("");
		printf("Collection #%d:\n",++c);
		if(sum & 1) {
			puts("Can't be divided.");
			continue;
		}
		for(i=1;i<=6;i++)
			if(coin[i] & 1)
				break;
		if(i > 6) {
			puts("Can be divided.");
			continue;
		}
		dp[0] = 1;
		sum /= 2;
		for(i=6;i>=1 && dp[sum] == 0;i--)
			for(j=0;j<coin[i] && dp[sum] == 0;j++)
				for(k=sum;k>=i;k--)
					if(dp[k-i])
						dp[k] = 1;
		
		if(dp[sum]) {
			puts("Can be divided.");
		} else {
			puts("Can't be divided.");
		}
	}
	
	return 0;
}
