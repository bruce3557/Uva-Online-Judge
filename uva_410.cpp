#include <stdio.h>
#include <string.h>
#include <algorithm>

int n,m;
int len[20];
int s[20];
double d[20][2];
double tt[20];
bool used[20];

double abs(double x) {
	return (x < 0) ? (-x) : x;
}

bool cmp(int a, int b) {
	return (a > b);
}

int main() {
	int t, cases=0;
	while(scanf("%d%d",&m,&n) != EOF) {
		double sum = 0;
		double av;
		memset(s, 0, sizeof(s));
		for(int i=0;i<n;++i) {
			scanf("%d",s+i);
			sum += s[i];
		}
		n = 2*m;
		av = sum/m;
		std::sort(s,s+n);
		printf("Set #%d\n",++cases);
		
		double answer = 0;
		for(int i=0;i<m;++i) {
			printf(" %d:",i);
			if(s[i])	printf(" %d",s[i]);
			if(s[m*2-1-i])	printf(" %d",s[m*2-1-i]);
			answer += abs(s[i]+s[m*2-1-i]-av);
			puts("");
		}
		
		printf("IMBALANCE = %.5lf\n",answer);
		puts("");
	}
	return 0;
}
