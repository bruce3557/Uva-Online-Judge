#include <stdio.h>
#include <math.h>
#define eps 1e-10

int main() {

	int i,j,n,num;
	double sum,min,aveg,s[2001],max,avg,ans;
	
	while(scanf("%d",&n) && n) {
		
		sum = 0.00;
		for(i=0;i<n;i++) {
			scanf("%lf",&s[i]);
			s[i] = (int)floor(s[i]*100+eps);
			sum += s[i];
		}
		
		min = max = 0;
		num = 0;
		//aveg = floor(sum/n+eps);
		avg  = floor(sum/n);
		for(i=0;i<n;i++) {
			if(s[i]+eps < avg)
				min += avg-s[i];
			if(s[i] > avg+1.00+eps)
				max += s[i]-avg-1.00;
		}
		//min /= (double)num;
		ans = min > max ? min : max;
		printf("$%.2lf\n",ans/100.00+eps);
		
	}

	return 0;
}
