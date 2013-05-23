#include <stdio.h>
#include <math.h>

int main() {
	long double x,ans;
	int t,d=0;
	
	scanf("%d",&t);
	while(t--) {
		if(d)	puts("");
		else	d = 1;
		scanf("%Lf",&x);
		ans = sqrtl(x);
		printf("%.0Lf\n",ans);
	}
	
	return 0;
}
