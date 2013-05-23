#include <stdio.h>

int dp[510][510];

int gcd(int a,int b){
	if(b == 0)	return a;
	return gcd(b,a%b);
}

int main(){
	int n,i,j,sum,G;
		
	while(scanf("%d",&n) && n){
		G = 0;
		for(i=1;i<n;i++)
			for(j=i+1;j<=n;j++)
				G+=gcd(i,j);
		printf("%d\n",G);
	}
	return 0;
}
