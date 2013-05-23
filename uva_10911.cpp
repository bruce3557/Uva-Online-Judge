#include <stdio.h>
#include <string.h>
#include <math.h>
#define Size (1<<16)

int n;
double dp[Size];
struct node {
	double x,y;
	
	void get() {
		scanf("%*s%lf%lf",&x,&y);
	}
}s[20];


inline double dist(int i,int j) {
	double dx=s[i].x-s[j].x;
	double dy=s[i].y-s[j].y;
	return sqrt(dx*dx+dy*dy);
}

double go(int comb) {
	//printf("comb = %d\n",comb);
	if(comb == 0)	return 0;
	if(dp[comb] != -1)	return dp[comb];
	
	double min=1e12;
	for(int i=0;i<n;++i)
		for(int j=0;j<i;++j) {
			//printf("%d %d\n",(1&(comb>>i)),(1&(comb>>j)));
			if((1&(comb>>i)) && (1&(comb>>j))) {
				//puts("VVVV");
				int tp=(1<<i),tpp=(1<<j);
				double temp = go((comb^tp)^tpp)+dist(i,j);;
				if(min > temp)	min = temp;
			}
		}
	return dp[comb] = min;
}

int main() {
	int c=0;
	
	while(scanf("%d",&n) && n) {
		n *= 2;
		int size=(1<<n)-1;
		//printf("%d\n",size);
		for(int i=0;i<=size;++i)
			dp[i] = -1;
		for(int i=0;i<n;++i)
			s[i].get();
		printf("Case %d: %.2lf\n",++c,go(size));
	}
	
	return 0;
}
