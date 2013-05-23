#include <stdio.h>
#include <string.h>
#include <math.h>
#define error (1e-5)

double x,y,c,s;

double Max(double x, double y) {
	return (x > y ? x : y);
}

int main() {
	double st,mid,ed,bound;

	while(scanf("%lf %lf %lf",&x,&y,&c) != EOF) {
		bound = Max(Max(x,y),c);
		
		st = 0, ed = bound;
		while((ed - st) > error) {
			mid = (st+ed)/2;
			double temp = 1/sqrt(x*x-mid*mid)+1/sqrt(y*y-mid*mid) - 1/c;
			if(temp < 0) st = mid;
			else		ed = mid;
		}
		
		printf("%.3lf\n",ed);
	}

	return 0;
}
