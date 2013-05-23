#include <stdio.h>
int main(){
	int t,n,k,x,min,max;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		min = 99999999, max = 0;
		while(k--){
			scanf("%d",&x);
			if(x*2 > n){
				if(min > (2*x-n)/2)		min = (2*x-n)/2;
				if(max < x)				max = x;
			} else {
				if(min > (n-2*x)/2)		min = (n-2*x)/2;
				if(max < n-x)			max = n-x;
			}
		}
		printf("%d %d\n",(n-2*min)/2,max);
	}
	return 0;
}
