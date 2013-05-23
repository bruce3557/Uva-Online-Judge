#include <stdio.h>
#include <math.h>
#define eps 1e-7

int p,q,r,s,t,u;

double test(double x) {
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

int main() {
	
	double st,ed,mid;
	
	while(scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u) != EOF) {
		st = 0.0000;
		ed = 1.0000;
		
		if(test(st)*test(ed) > 0.0000) {
			puts("No solution");
			continue;
		}
		
		if(test(ed) == 0.0000) {
			printf("%.4lf\n",ed);
			continue;
		}
		
		if(test(st) == 0.0000) {
			printf("%.4lf\n",st);
			continue;
		}
		
		while(ed-st > eps) {
			mid = (st+ed)/2;
			if(test(mid) == 0.0000) {
				ed = mid;
				break;
			}
			if(test(mid)*test(st) < 0.0000) {
				ed = mid;
			} else if(test(mid)*test(ed) < 0.0000) {
				st = mid;
			}
		}
		
		printf("%.4lf\n",ed);
	}

	return 0;
}
