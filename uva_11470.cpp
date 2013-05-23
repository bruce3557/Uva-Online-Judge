#include <stdio.h>

int map[30][30];

int main() {
	int c = 0;
	int i,j,n,sum;
	
	while(scanf("%d",&n) && n) {
	
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%d",&map[i][j]);
				
		printf("Case %d:",++c);
		for(i=1;i<=(n+1)/2;i++){
			sum = 0;
			for(j=i;j<=n-i+1;j++)
				sum += map[i][j]+map[n-i+1][j];
			for(j=i+1;j<=n-i;j++)
				sum += map[j][i]+map[j][n-i+1];
			if((n&1) && i == (n+1)/2)
				printf(" %d",sum/2);
			else
				printf(" %d",sum);
		}
		puts("");
	}
	
	return 0;
}
