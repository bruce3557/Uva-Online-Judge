#include <stdio.h>

int s[10010],n,m,sum;

int gcd(int a,int b) {
	if(b == 0)	return a;
	return gcd(b,a%b);
}

int main() {
	int i,j,g;
	
	while(scanf("%d%d",&n,&m) && n+m) {
		sum = 0;
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++)
				scanf("%d",s+i);
			sum += s[i];
		}
		for(i=0;i<n;i++) {
			g = gcd(s[i],sum);
			printf("%d / %d\n",s[i]/g,sum/g);
		}
	}
	
	return 0;
}
