#include <stdio.h>
#include <math.h>

int dp[30][30][10][15][2];
char used[30][30][10][15][2];

int go(int t1,int t2,int at,int d) {
	if(t1 <= 0 || t2 <= 0) {
		printf("%d %d %d %d: %d\n",t1,t2,at,d,1);
		return 1;
	}
	if(dp[t1][t2][at][d][0] != -1){
		printf("%d %d %d %d: %d\n",t1,t2,at,d,dp[t1][t2][at][d][0]);
		return dp[t1][t2][at][d][0];
	}
	/*if(used[t1][t2][at][d][0] == 1){
		printf("%d %d %d %d: %d\n",t1,t2,at,d,0);
		return 0;
	}*/
	//used[t1][t2][at][d][0] = 1;
	int sum = 0;
	for(int i=1;i<=6;i++) {
		if(i <= at)
			sum += go(t1+d,t2-d,at,d);
		else
			sum += go(t1-d,t2+d,at,d);
	}
	printf("%d %d %d %d: %d\n",t1,t2,at,d,sum);
	return dp[t1][t2][at][d][0] = sum;
}

int se(int t1,int t2,int at,int d) {
	if(t1 <= 0) {
		printf("%d %d %d %d: %d\n",t1,t2,at,d,0);
		return 0;
	}
	if(t2 <= 0) {
		printf("%d %d %d %d: %d\n",t1,t2,at,d,1);
		return 1;
	}
	if(dp[t1][t2][at][d][1] != -1){
		printf("%d %d %d %d: %d\n",t1,t2,at,d,dp[t1][t2][at][d][1]);
		return dp[t1][t2][at][d][1];
	}
	/*if(used[t1][t2][at][d][1] == 1){
		printf("%d %d %d %d: %d\n",t1,t2,at,d,0);
		return 0;
	}
	used[t1][t2][at][d][1] = 1;*/
	int sum = 0;
	for(int i=1;i<=6;i++) {
		if(i <= at)
			sum += se(t1+d,t2-d,at,d);
		else
			sum += se(t1-d,t2+d,at,d);
	}
	printf("%d %d %d %d: %d\n",t1,t2,at,d,sum);
	return dp[t1][t2][at][d][1] = sum;
}

int main() {
	int EV1,EV2,AT,D,t1,t2;
	int i,j,k,l;
	
	for(i=0;i<=10;i++)
		for(j=0;j<=10;j++)
			for(k=0;k<=5;k++)
				for(l=0;l<=10;l++)
					dp[i][j][k][l][0] = dp[i][j][k][l][1] = -1;
	
	while(scanf("%d%d%d%d",&EV1,&EV2,&AT,&D) && EV1+EV2+AT+D != 0) {
		go(EV1,EV2,AT,D);
		puts("");
		se(EV1,EV2,AT,D);
		printf("%d %d\n",dp[EV1][EV2][AT][D][1],dp[EV1][EV2][AT][D][0]);
		printf("%.1lf\n",(double)dp[EV1][EV2][AT][D][1]/dp[EV1][EV2][AT][D][0]*100.0);
	}
	
	return 0;
}
