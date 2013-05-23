#include <stdio.h>
#include <math.h>

int main() {
	long long n;
	
	while(scanf("%lld",&n) != EOF) {
		
		long long ans = (long long)(-1+sqrt(1+8*n)+1e-5)/2;
		long long num;
		(n == ans*(ans+1)/2) ? (num = n-ans*(ans-1)/2, printf("%lld/%lld\n",ans-num+1,num)) :
							   (num = n-ans*(ans+1)/2, printf("%lld/%lld\n",ans-num+2,num)) ; 
		
	}
	
	return 0;
}
