#include <stdio.h>
#include <string.h>

int n,m;
int count[30];
int s[30][30];
bool dp[210][30];

int main() {
	int t;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&m,&n);
		for(int i=1;i<=n;++i) {
			scanf("%d",count+i);
			for(int j=0;j<count[i];++j)
				scanf("%d",&s[i][j]);
		}
		
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		for(int i=1;i<=n;++i)
			for(int j=0;j<count[i];++j)
				for(int k=s[i][j];k<=m;++k)
					if(dp[k-s[i][j]][i-1] == 1)
						dp[k][i] = 1;

		int ans;
		for(ans=m;ans>0 && dp[ans][n] == false;--ans);
		if(ans > 0)
			printf("%d\n",ans);
		else
			puts("no solution");
	}

	return 0;
}
