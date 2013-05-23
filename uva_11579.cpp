#include <stdio.h>
#include <math.h>
#include <algorithm>

double s[10010],max;

double abs(double x) {
	if(x < 0)	return -x;
	return x;
}

int main() {
	int n,i,j,k;
	int t;
	double tmp,tt;
	
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lf",s+i);
		max = 0.00;
		std::sort(s,s+n);
		i=n-1,j=n-2,k=n-3;
		while(1) {
			if(i < 0 || j < 0 || k < 0)	break;
			
			if(s[i] < s[j]+s[k]) {
				tmp = (s[i]+s[j]+s[k])/2;
				tt = sqrt(tmp*(tmp-s[i])*(tmp-s[j])*(tmp-s[k]));
				if(max < tt)
					max = tt;
			}
			i--,j--,k--;
		}
		printf("%.2lf\n",max);
	}
	
	return 0;
}
